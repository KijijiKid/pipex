/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:32:43 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/29 15:27:44 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int	infile_fd;
	int	outfile_fd;


	outfile_fd = open_file(argv[argc - 1], O_WRONLY);
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0)
	{
		// Max args here is 4 (excluding prgrm), ARG [1] & [2] are for heredoc
		init_heredoc(argv[2]);
	}
	else
	{
		// Logic for 4<= pipes 
		infile_fd = open_file(argv[1], O_RDONLY);
		run_pipex(argv, argc , envp, infile_fd, outfile_fd);
	}
	return 0;
}
