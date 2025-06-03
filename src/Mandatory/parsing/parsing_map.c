/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:42:13 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 09:36:30 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

int	check_map(int fd, t_info *info)
{
	char	*copymap;
	int		coutline;

	coutline = 0;
	copymap = get_next_line(fd);
	if (!copymap)
		exit_with_error(fd, info, "Error\nMemory allocation failed\n", NULL);
	while (copymap)
	{
		if (take_infos(copymap, info))
			exit_with_error(fd, info, "Error\nInvalid map data\n", copymap);
		if (info->no && info->so && info->we && info->ea && info->f && info->c)
			break ;
		free(copymap);
		copymap = get_next_line(fd);
		coutline++;
	}
	free(copymap);
	if (!info->no || !info->so || !info->we || !info->ea || !info->f
		|| !info->c)
		exit_with_error(fd, info, "Error\nTexture missing\n", NULL);
	return (coutline);
}

int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == '\n')
		return (1);
	return (0);
}

static int	stock_map2(char *str, t_info *info, int *coutline, int *map_started)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i] || str[i] == '\n')
	{
		if (*map_started == 0)
			return (0);
		else
		{
			free_info_with_error_msg(info, "Error\nEmpty line inside map\n");
			return (1);
		}
	}
	while (is_valid_map_char(str[i]))
		i++;
	if (str[i])
	{
		free_info_with_error_msg(info, "Error\nBad character found in map\n");
		return (1);
	}
	*map_started = 1;
	(*coutline)++;
	return (0);
}

int	stock_map(int fd, t_info *info, int *coutline)
{
	char	*str;
	int		skipline;
	int		map_started;

	skipline = 0;
	map_started = 0;
	str = get_next_line(fd);
	if (!str)
	{
		ft_putstr("Error\nNo map provided or memory allocation failed\n");
		free_info(info);
		clean_exit(fd, str);
	}
	while (str)
	{
		if (stock_map2(str, info, coutline, &map_started))
			clean_exit(fd, str);
		free(str);
		str = get_next_line(fd);
		skipline++;
	}
	return (skipline - *coutline);
}

void	copy_map(int fd, t_info *info, int coutline, int skipline)
{
	int		i;
	char	*skip;

	i = 0;
	info->map = malloc(sizeof(char *) * (coutline + 1));
	if (!info->map)
	{
		free_info(info);
		close(fd);
		exit(1);
	}
	while (skipline + 1 > 0)
	{
		skip = get_next_line(fd);
		free(skip);
		skipline--;
	}
	while (i < coutline)
	{
		info->map[i] = get_next_line(fd);
		i++;
	}
	info->map[i] = NULL;
}
