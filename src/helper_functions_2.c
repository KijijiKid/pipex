/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:46:50 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/29 15:40:29 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_piped_cmd(char *cmd, char **envp, int pipe_read_end, int pipe_write_end)
{
	int		pid;
	char	**cmd_2D_array;
	char	*path_str;
	char	*cmd_path; 

	cmd_2D_array = ft_split(cmd, ' ');
	path_str = extract_path(envp);
	cmd_path = access_path(cmd_2D_array[0], path_str);
	pid = fork();
	if (pid == -1)
		perror("Fork failed.");
	if (pid == 0)
	{
		dup2(pipe_read_end, STDIN_FILENO);
		close(pipe_read_end);
		dup2(pipe_write_end, STDOUT_FILENO);
		close(pipe_write_end);
		execve(cmd_path, cmd_2D_array, envp);
	}
	else 
	{
		wait(NULL);
		free2d(cmd_2D_array);
		free(cmd_path);
	}
	close(pipe_write_end);
}

/// @brief This runs either the last or the first command.
/// This is made in a seperate function because
/// we won't pipe something here, rather than just taking
/// or providing in/output from a given fd
/// @param cmd 1D Array with cmd and eventaully flags
/// @param envp enviroment 2D-Array
/// @param in_fd file where execve is taking is taking its
/// input from
/// @param out_fd file where execve is sending output to
void	run_first_or_last_cmd(char *cmd, char **envp, int in_fd, int out_fd)
{
	int		pid;
	char	**cmd_2D_array;
	char	*path_str;
	char	*cmd_path; // The dir where bin is found in

	cmd_2D_array = ft_split(cmd, ' ');
	path_str = extract_path(envp);
	cmd_path = access_path(cmd_2D_array[0], path_str);
	pid = fork();
	if (pid == -1)
		perror("Fork failed.");
	if (pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
		execve(cmd_path, cmd_2D_array, envp);
	}
	else 
	{
		wait(NULL);
		free2d(cmd_2D_array);
		free(cmd_path);
	}
}

/// @brief This fnc goes through each dir checking
/// inside for the existence of the bin with the name
/// provided as arg
/// @param cmd bin name
/// @param paths String with all bin dir
/// @return allocated cmd_path where the bin is located
char	*access_path(char *cmd,char *paths)
{
	char	**splitted_dir_paths;
	char	**tmp_for_freeing;
	char	*cmd_path;

	splitted_dir_paths = ft_split(paths, ':');
	tmp_for_freeing = splitted_dir_paths;
	cmd = ft_strjoin("/", cmd);
	while(*splitted_dir_paths)
	{
		cmd_path = ft_strjoin(*splitted_dir_paths, cmd);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		splitted_dir_paths++;
	}
	free(cmd);
	free2d(tmp_for_freeing);
	return (cmd_path);
}

/// @brief Gets the 2D environment array and extracts the
/// all directories 
/// @param envp 2D Array of the env the program
/// runs at
/// @return A string of the PATH's excluding "PATH=",
/// the String is NULL-Terminated
char	*extract_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, ft_strlen("PATH=")))
		*envp += 1;
	return (*envp + 5);
}
