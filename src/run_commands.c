/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandre <mandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:12:30 by mandre            #+#    #+#             */
/*   Updated: 2025/08/06 20:12:11 by mandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(char *cmd, char **envp, int in_fd, int out_fd)
{
	char	**paths_2d;
	char	**cmd_2d;
	char	*cmd_path;
	int		pid;

	pid = fork();
	if (pid == -1)
		set_error(2);
	if (pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
		dup2(out_fd, STDOUT_FILENO);
		close (out_fd);
		paths_2d = extract_path(envp);
		cmd_2d = ft_split(cmd, ' ');
		cmd_path = access_path(cmd_2d[0], paths_2d);
		if (!paths_2d || !cmd_2d || !cmd_path)
			set_error(20);
		if (execve(cmd_path, cmd_2d, envp) == -1)
			execve_failed(paths_2d, cmd_2d, cmd_path);
	}
	else
		wait(NULL);
	throw_error();
}

void	run_commands_herdoc(int argc, char **argv, char **envp, int *fd_arr)
{
	int	i;
	int	pipe_fds[2][2];
	int	*new_pipe;
	int	*old_pipe;

	new_pipe = pipe_fds[0];
	old_pipe = pipe_fds[1];
	create_pipe(new_pipe);
	run_cmd(argv[3], envp, fd_arr[0], new_pipe[1]);
	i = 4;
	while (i < (argc - 2))
	{
		create_pipe(old_pipe);
		run_cmd(argv[i], envp, new_pipe[0], old_pipe[1]);
		swap_ptrs(&new_pipe, &old_pipe);
		i++;
	}
	run_cmd(argv[i], envp, new_pipe[0], fd_arr[1]);
}

void	run_commands(int argc, char **argv, char **envp, int *fd_arr)
{
	int	i;
	int	pipe_fds[2][2];
	int	*new_pipe;
	int	*old_pipe;

	new_pipe = pipe_fds[0];
	old_pipe = pipe_fds[1];
	create_pipe(new_pipe);
	run_cmd(argv[2], envp, fd_arr[0], new_pipe[1]);
	i = 3;
	while (i < (argc - 2))
	{
		create_pipe(old_pipe);
		run_cmd(argv[i], envp, new_pipe[0], old_pipe[1]);
		// close(new_pipe[0]);
		// close(new_pipe[1]);
		swap_ptrs(&new_pipe, &old_pipe);
		i++;
	}
	run_cmd(argv[i], envp, new_pipe[0], fd_arr[1]);
}
