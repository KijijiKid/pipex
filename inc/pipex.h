/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:08 by mandre            #+#    #+#             */
/*   Updated: 2025/08/04 17:47:45 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Includes -- BEGIN
# include <stdio.h>
# include <unistd.h>
# include "../modules/my_libft/libft.h"
//Includes -- END

//MVP -> functions
char	*access_path(char *cmd,char *paths);
char	*extract_path(char **envp);
int		open_file(char *file_name, int flag);

/// No heredoc execution functions
void	run_pipex(char **argv, int argc, char **envp, int fd_in_out[]);
void	run_first_or_last_cmd(char *cmd, char **envp, int in_fd, int out_fd);
void	run_piped_cmd(char *cmd, char **envp, int pipe_read_end, int pipe_write_end);

//Special Functions
void	init_heredoc(char *lim);

//Norminette shorteners
void	close_pip(int *curr_pipe, int *next_pipe);

#endif