/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:34:42 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/27 17:21:11 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief This function returns the file descriptor 
/// given as parameter
/// @param file_name 2D Array, can be a relative or 
/// absolute path
int	open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("File does not exist, please check path or permissions of the file.");
	}
	return (fd);
}

/// @brief This fuction gets a command name
/// as string, then 
/// @param cmd 
void	run_cmd(char *cmd, char **envp, int fd)
{
	int			proc_id;
	char		*path;
	char 		*cmd_path;
	char		*cmd_args[2];


	cmd_args[0] = cmd;
	cmd_args[1] = NULL;
 	path = extract_path(envp);
 	cmd_path = access_path(cmd, path);
	proc_id = fork();
	if (proc_id == 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
		execve(cmd_path, cmd_args, envp);
	}
	else
		wait(NULL);
	return ;
}