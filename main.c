/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:32:43 by mateoandre        #+#    #+#             */
/*   Updated: 2025/08/06 17:13:20 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd_arr[2];

	inpt_parsing(argc, argv);
	fd_arr[1] = open("outfile.txt", O_WRONLY);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		fd_arr[0] = init_here_doc(argv[2]);
		run_commands_herdoc(argc, argv, envp, fd_arr);
	}
	else
	{
		fd_arr[0] = open("infile.txt", O_RDONLY);
		run_commands(argc, argv, envp, fd_arr);
	}
}
