/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:34:57 by mandre            #+#    #+#             */
/*   Updated: 2025/08/06 19:10:19 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_failed(char	**paths_2d, char	**cmd_2d, char	*cmd_path)
{
	free(cmd_path);
	free2d(cmd_2d);
	free2d(paths_2d);
	set_error(4);
	throw_error();
}

void	swap_ptrs(int *ptr1, int *ptr2)
{
	int	*tmp;

	tmp = ptr2;
	ptr2 = ptr1;
	ptr1 = tmp;
}

char	**extract_path(char **envp)
{
	char	**path_2d;

	while (envp)
	{
		if (ft_strncmp("PATH=", *envp, ft_strlen("PATH=")))
		{
			path_2d = ft_split((*envp + 5), ':');
			return (path_2d);
		}
		envp++;
	}
	return (NULL);
}

char	*access_path(char *cmd, char **paths_2d)
{
	char	*path_cmd;
	char	*full_path;

	path_cmd = ft_strjoin("/", cmd);
	while (*paths_2d)
	{
		full_path = ft_strjoin(*paths_2d, path_cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		paths_2d++;
	}
	return (NULL);
}

void	create_pipe(int *fd_arr)
{
	if (pipe(fd_arr) == -1)
		set_error(3);
	throw_error();
}
