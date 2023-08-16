/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:44:18 by kkilitci          #+#    #+#             */
/*   Updated: 2023/08/14 15:35:23 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_struct_one(t_pipex *pipexx, char **argv, char **envp)
{
	int	i;

	i = 0;
	if (pipe(pipexx->pipe) < 0)
		msg_error(ERR_PIPE);
	if (find_replace(argv[2]))
		pipexx->left_cmd = ft_split(argv[2], 39);
	else
		pipexx->left_cmd = ft_split(argv[2], ' ');
	while (pipexx->left_cmd[i])
		i++;
	pipexx->left_cmd[i] = NULL;
	i = -1;
	if (find_replace(argv[3]))
		pipexx->right_cmd = ft_split(argv[3], 39);
	else
		pipexx->right_cmd = ft_split(argv[3], ' ');
	while (pipexx->right_cmd[i])
		i++;
	pipexx->right_cmd[i] = NULL;
	ft_struct_two(pipexx, argv, envp);
	pipe(pipexx->pipe);
}

void	call_parent(t_pipex *pipexx)
{
	int	exec_return;

	close(pipexx->pipe[1]);
	if (dup2(pipexx->pipe[0], STDIN_FILENO) == -1)
	{
		pipexx->exit_state = EXIT_FAILURE;
		perror("dup2 for STDIN1");
	}
	if (dup2(pipexx->outfile_fd, STDOUT_FILENO) == -1)
	{
		pipexx->exit_state = 5;
		perror("dup2 for STDOUT2");
		exit(5);
	}
	exec_return = execve (pipexx->path2, pipexx->right_cmd, pipexx->envp);
	if (exec_return == -1)
	{
		pipexx->execev_error = 6;
		msg(ERR_CMD);
		exit(1);
	}
	close(pipexx->pipe[0]);
	exit(0);
}

void	call_child(t_pipex *pipexx)
{
	int	exec_return;

	close(pipexx->pipe[0]);
	if (dup2 (pipexx->infile_fd, STDIN_FILENO) == -1)
	{
		pipexx->exit_state = EXIT_FAILURE;
		perror("dup2 for STDIN");
	}
	if (dup2 (pipexx->pipe[1], STDOUT_FILENO) == -1)
	{
		pipexx->exit_state = EXIT_FAILURE;
		perror("dup2 for STDOUT1");
	}
	exec_return = execve(pipexx->path, pipexx->left_cmd, pipexx->envp);
	if (exec_return == -1)
	{
		msg (ERR_CMD);
		pipexx->execev_error = 6;
		exit(1);
	}
	close (pipexx->pipe[1]);
	exit (0);
}

void	pipexfree(t_pipex *pipexx)
{
	int	i;

	i = -1;
	while (pipexx->left_cmd[++i])
		free(pipexx->left_cmd[i]);
	i = -1;
	while (pipexx->right_cmd[++i])
		free(pipexx->right_cmd[i]);
	free(pipexx->left_cmd);
	free(pipexx->right_cmd);
	free(pipexx->path2);
	free(pipexx->path);
	close(pipexx->pipe[0]);
	close(pipexx->pipe[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipexx;
	int		child_pid;
	int		parent_pid;
	int		status;

	if (argc != 5)
		return (msg(ERR_INPUT));
	ft_struct_one(&pipexx, argv, envp);
	child_pid = fork();
	if (child_pid == 0)
		call_child (&pipexx);
	waitpid (child_pid, &status, WNOHANG | WUNTRACED);
	if (child_pid != 0)
	{
		parent_pid = fork();
		if (parent_pid == 0)
			call_parent(&pipexx);
	}
	pipexfree(&pipexx);
	retur_exit(&pipexx);
	return (0);
}
