/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateoandre <mateoandre@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:46:50 by mateoandre        #+#    #+#             */
/*   Updated: 2025/07/27 16:07:37 by mateoandre       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief This fnc goes through each dir checking
/// inside for the existence of the bin with the name
/// provided as arg
/// @param cmd bin name
/// @param paths String with all bin dir
/// @return allocated cmd_path where the bin is located
char	*access_path(char *cmd,char *paths)
{
	char	**splitted_dir_paths;
	char	**tmp_for_freeing;
	char	*cmd_path;

	splitted_dir_paths = ft_split(paths, ':');
	tmp_for_freeing = splitted_dir_paths;
	cmd = ft_strjoin("/", cmd);
	while(*splitted_dir_paths)
	{
		cmd_path = ft_strjoin(*splitted_dir_paths, cmd);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		splitted_dir_paths++;
	}
	free(cmd);
	free2d(tmp_for_freeing);
	return (cmd_path);
}

/// @brief Gets the 2D env array and extracts the
/// all directories 
/// @param envp 2D Array of the env the program
/// runs at
/// @return A string of the PATH's excluding "PATH=",
/// the String is NULL-Terminated
char	*extract_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, ft_strlen("PATH=")))
		*envp += 1;
	return (*envp + 5);
}
