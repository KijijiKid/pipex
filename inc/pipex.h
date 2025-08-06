/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:08 by mandre            #+#    #+#             */
/*   Updated: 2025/08/06 19:57:15 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Includes -- BEGIN
# include <stdio.h>
# include <unistd.h>
# include "../modules/my_libft/libft.h"
//Includes -- END

//Helper Fncs
void	create_pipe(int *fd_arr);
char	**extract_path(char **envp);
char	*access_path(char *cmd, char **paths_2d);
void	swap_ptrs(int **ptr1, int **ptr2);
void	execve_failed(char	**paths_2d, char	**cmd_2d, char	*cmd_path);

//Run Commands
void	run_commands(int argc, char **argv, char **envp, int *fd_arr);
void	run_commands_herdoc(int argc, char **argv, char **envp, int *fd_arr);

//Here_doc
int		init_here_doc(char *limiter);

//Input parsing
void	inpt_parsing(int argc, char **argv);

//Error Funcions
void	set_error(int new_status);
void	throw_error(void);

#endif