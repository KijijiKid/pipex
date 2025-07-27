#ifndef PIPEX_H
# define PIPEX_H

//Includes -- BEGIN
#include <stdio.h>
#include <unistd.h>
#include "../modules/my_libft/libft.h"
//Includes -- END

//MVP -> functions
char	*access_path(char *cmd,char *paths);
char	*extract_path(char **envp);
int		open_file(char *file_name);
void	run_cmd(char *cmd, char **envp, int fd);

//Special Functions
void	init_heredoc(char *lim);

#endif