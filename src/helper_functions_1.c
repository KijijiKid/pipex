/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 06:34:42 by mateoandre        #+#    #+#             */
/*   Updated: 2025/08/04 17:28:21 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	swap_ptrs(int **a, int **b)
{
	int		*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/// @brief This fuction firstly takes a command
/// then iterates through an two-dimensional array piping a given 
/// amount of commands through the next cmd to execve
/// as string, then 
/// @param cmd 
/// @param fd_in_out Its an 2D array always containing infile on index 0 and
/// the outfile on index 1 -> Norminette reasons
void	run_pipex(char **argv, int argc, char **envp, int fd_in_out[])
{
	int	i;
	int	pipe_fd[2][2];
	int	*curr_pipe;
	int	*next_pipe;

	curr_pipe = pipe_fd[0];
	next_pipe = pipe_fd[1];
	if (pipe(curr_pipe) < 0)
		perror("Pipe creation failed");
	i = 2;
	run_first_or_last_cmd(argv[i], envp, fd_in_out[0], curr_pipe[1]);
	close(curr_pipe[1]);
	i++;
	while (i < (argc - 2))
	{
		if (pipe(next_pipe) < 0)
			perror("Pipe creation failed");
		run_piped_cmd(argv[i], envp, curr_pipe[0], next_pipe[1]);
		close(curr_pipe[0]);
		swap_ptrs(&curr_pipe, &next_pipe);
		i++;
	}
	run_first_or_last_cmd(argv[i], envp, curr_pipe[0], fd_in_out[1]);
	close(curr_pipe[0]);
	close(curr_pipe[1]);
	close(next_pipe[0]);
	close(next_pipe[1]);
}

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
