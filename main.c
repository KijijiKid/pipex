/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:32:43 by mateoandre        #+#    #+#             */
/*   Updated: 2025/08/04 18:36:42 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd_in_out[2];


	fd_in_out[1] = open_file(argv[argc - 1], O_WRONLY);
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0)
		init_heredoc(argv[2]);
	else
	{
		fd_in_out[0] = open_file(argv[1], O_RDONLY);
		run_pipex(argv, argc, envp, fd_in_out);
	}
	return (0);
}
