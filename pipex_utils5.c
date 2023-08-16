/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:03:14 by kkilitci          #+#    #+#             */
/*   Updated: 2023/08/14 14:13:26 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_struct_two(t_pipex *pipexx, char **argv, char **envp)
{
	pipexx->infile_fd = open(argv[1], O_RDONLY);
	pipexx->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pipexx->envp = envp;
	pipexx->path = ft_access(pipexx->left_cmd[0], ft_get_path(envp));
	pipexx->path2 = ft_access(pipexx->right_cmd[0], ft_get_path(envp));
	pipexx->exit_state = 0;
	pipexx->execev_error = -2;
}
