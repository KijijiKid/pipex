/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:32:43 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/28 16:30:21 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int	infile_fd;
	int	outfile_fd;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		perror("Attempt to create a pipe failed.");
	infile_fd = open_file(argv[1], O_RDONLY);
	outfile_fd = open_file(argv[argc - 1], O_WRONLY);
	run_cmd(argv[2], envp, infile_fd, pipe_fd[1]);
	close(pipe_fd[1]);
	run_cmd(argv[3], envp, pipe_fd[0], outfile_fd);
	close(pipe_fd[0]);
	return 0;
}
