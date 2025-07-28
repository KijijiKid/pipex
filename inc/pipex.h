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
int	open_file(char *file_name, int flag);
void	run_cmd(char *cmd, char **envp, int infile_fd, int outfile_fd);

//Special Functions
void	init_heredoc(char *lim);

#endif