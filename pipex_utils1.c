/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:28:26 by kkilitci          #+#    #+#             */
/*   Updated: 2023/08/14 15:01:53 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_replace(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_wordput(const char *s, char c, char **strs)
{
	size_t	j;
	size_t	i;
	size_t	flag;
	size_t	len;

	len = 0;
	flag = 1;
	j = 0;
	i = 0;
	while (s[j])
	{
		len = 0;
		while (s[j] == c)
			j++;
		while (s[j] && s[j] != c && ++len)
		{
			j++;
			flag = 1;
		}
		if (flag == 1)
			strs[i++] = ft_substr(s, j - len, len);
		flag = 0;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!strs)
		return (0);
	if (!ft_wordcount(s, c))
	{
		strs[0] = 0;
		return (strs);
	}
	return (ft_wordput(s, c, strs));
}
