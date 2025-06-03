/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:23:04 by drabarza          #+#    #+#             */
/*   Updated: 2025/05/27 00:48:08 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*copy_line(char *stock, int lenght, int value)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char) * (lenght + value) + 1);
	if (!tab)
		return (NULL);
	while (i < lenght + value)
	{
		tab[j] = stock[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static char	*cut_and_save(char **stock)
{
	char	*line;
	char	*temp;

	line = copy_line(*stock, ft_strlen_end_line(*stock), 1);
	temp = ft_strdup(ft_strchr(*stock, '\n'));
	free(*stock);
	*stock = temp;
	return (line);
}

static char	*last_line(char **stock, int bytes_read)
{
	char	*line;

	if (ft_strchr(*stock, '\n'))
		return (cut_and_save(stock));
	if (bytes_read == BUFFER_SIZE)
		line = copy_line(*stock, ft_strlen_end_line(*stock), 1);
	else
		line = copy_line(*stock, ft_strlen(*stock), 0);
	if (bytes_read == BUFFER_SIZE)
		*stock = ft_strdup(ft_strchr(*stock, '\n'));
	else
	{
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

static int	extract_line(char **buffer, int *bytes_read, char **stock, int fd)
{
	while (!ft_strchr(*buffer, '\n') && *bytes_read >= BUFFER_SIZE)
	{
		*stock = ft_strjoin(*stock, *buffer);
		free(*buffer);
		if (stock == NULL)
			return (1);
		*buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
		if (!*buffer)
			return (1);
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[*bytes_read] = '\0';
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(stock, '\n'))
		return (cut_and_save(&stock));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0 && (!stock || stock[0] == '\0'))
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	if (extract_line(&buffer, &bytes_read, &stock, fd))
		return (NULL);
	stock = ft_strjoin(stock, buffer);
	free(buffer);
	if (stock == NULL)
		return (NULL);
	return (last_line(&stock, bytes_read));
}
