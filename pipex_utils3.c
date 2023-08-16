/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:12:26 by kkilitci          #+#    #+#             */
/*   Updated: 2023/08/14 17:06:19 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

char	*ft_access(char *args, char *allpath)
{
	char	**command_paths;
	char	*command;
	char	*arg;
	char	*trim;
	int		i;

	i = -1;
	command_paths = ft_split(allpath, ':');
	arg = ft_strjoin("/", args);
	trim = ft_strtrim(arg, " ");
	while (command_paths[++i])
	{
		command = ft_strjoin(command_paths[i], trim);
		if (access(command, X_OK | R_OK) == 0)
		{
			free(arg);
			free_acces(command_paths, trim);
			return (command);
		}
		free(command);
	}
	free(arg);
	free_acces(command_paths, trim);
	return (NULL);
}

void	free_acces(char **command_paths, char *trim)
{
	int	j;

	j = -1;
	while (command_paths[++j])
		free(command_paths[j]);
	free(command_paths);
	free(trim);
}

char	*ft_get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0) 
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
