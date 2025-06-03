/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:22:59 by drabarza          #+#    #+#             */
/*   Updated: 2025/05/27 00:48:05 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlen_end_line(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = -1;
	j = 0;
	tab = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!tab)
		return (NULL);
	while (lens1 > ++i)
		tab[i] = s1[i];
	while (lens1 + lens2 > i)
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)s;
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return (&tab[i + 1]);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return (&tab[i]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
