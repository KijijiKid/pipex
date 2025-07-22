/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:00:46 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/22 10:30:52 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/// @brief This function initializes an heredoc reading from stdin
/// @param lim The limeter parameter
void	init_heredoc(char *lim)
{
	char	*line;
	char	*lim2;

	lim2 = ft_strjoin(lim, "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			write(1, "ERR\n", 4);
			break ;
		}
		if (ft_strncmp(lim2, line, ft_strlen(lim2)) == 0)
		{
			free (line);
			break ;
		}
		free(line);
	}
	free(lim2);
}
