/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:00:46 by mateoandre        #+#    #+#             */
/*   Updated: 2025/08/06 20:36:36 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief Initializes a here_doc in a child process
/// @param limiter Limiter character
/// @return The read-end of the pipe the content of here_doc
/// was writting to
int	init_here_doc(char *limiter)
{
	int		pid;
	char	*line;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		set_error(2);
	pid = fork();
	if (pid == -1)
		set_error(1);
	throw_error();
	if (pid == 0)
	{
		close(pipe_fds[0]);
		while (1)
		{
			write(1, "here_doc> ", ft_strlen("here_doc> "));
			line = get_next_line(STDIN_FILENO);
			if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
			{
				free(line);
				break ;
			}
			write(pipe_fds[1], line, ft_strlen(line));
			free(line);
		}
		close(pipe_fds[1]);
		exit(0);
	}
	else
		return (wait(NULL), close(pipe_fds[1]), pipe_fds[0]);
}
