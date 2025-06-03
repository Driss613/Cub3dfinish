/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:53:56 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_width(char **map, int map_height)
{
	int	max_width;
	int	len;
	int	i;

	max_width = 0;
	i = 0;
	while (i < map_height)
	{
		len = 0;
		while (map[i][len] && map[i][len] != '\n')
			len++;
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}
