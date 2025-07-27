/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:32:43 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/27 16:47:29 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int	i;
	int fd;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
			fd = open_file(argv[i]);
		else
			run_cmd(argv[i], envp, fd);
		i++;
	}
	return 0;
}
