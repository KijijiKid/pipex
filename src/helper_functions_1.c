/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:34:42 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/28 16:05:49 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief This function returns the file descriptor 
/// given as parameter
/// @param file_name 2D Array, can be a relative or 
/// absolute path
int	open_file(char *file_name, int flag)
{
	int	fd;

	fd = open(file_name, flag);
	if (fd < 0)
	{
		perror("File does not exist, please check path or permissions of the file.");
	}
	return (fd);
}

/// @brief This fuction gets a command name
/// as string, then 
/// @param cmd 
void	run_cmd(char *cmd, char **envp, int infile_fd, int outfile_fd)
{
	int			proc_id;
	char		*path;
	char 		*cmd_path;
	char		**cmd_args;


	cmd_args = ft_split(cmd, ' ');
 	path = extract_path(envp);
 	cmd_path = access_path(cmd_args[0], path);
	proc_id = fork();
	if (proc_id == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		execve(cmd_path, cmd_args, envp);
	}
	else
	{
		wait(NULL);
		free2d(cmd_args);
	}
	return ;
}