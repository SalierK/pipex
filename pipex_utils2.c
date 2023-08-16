/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:33:49 by kkilitci          #+#    #+#             */
/*   Updated: 2023/08/14 15:05:39 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*rt;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	rt = (char *)malloc(sizeof(char) * (i + 1));
	if (!rt)
		return (0);
	i = 0;
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	rt[i] = 0;
	return (rt);
}

char	*ft_nullchecker(char const *s1, char const *s2)
{
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*rt;

	i = 0;
	if (!s1 || !s2)
		return (ft_nullchecker(s1, s2));
	rt = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rt)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (i < len1)
	{
		rt[i] = s1[i];
		i++;
	}
	while (i < len2 + len1)
	{
		rt[i] = s2[i - len1];
		i++;
	}
	rt[len1 + len2] = 0;
	return (rt);
}
