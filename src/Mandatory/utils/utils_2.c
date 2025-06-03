/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:36:13 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 09:36:30 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = (char *)s;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return (&tab[i]);
		}
		i--;
	}
	return (NULL);
}

int	ft_strlen_with_newline(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	clean_exit(int fd, char *str)
{
	if (str)
		free(str);
	close(fd);
	exit(1);
}

void	exit_with_error(int fd, t_info *info, char *error_msg, char *str)
{
	ft_putstr(error_msg);
	free_info(info);
	clean_exit(fd, str);
}
