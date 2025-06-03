/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 06:48:08 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static void	check_flood_fill_bounds(char **str, t_info *info)
{
	int	x;
	int	y;

	x = (int)info->pos.x;
	y = (int)info->pos.y;
	if (x == 0 || y == 0
		|| x > ft_strlen_with_newline(str[y - 1])
		- 1 || x > ft_strlen_with_newline(str[y
				+ 1]) - 1 || str[y][x + 1] == '\n'
		|| str[y][x + 1] == '\0')
	{
		free_info(info);
		free_tab(str);
		ft_putstr("Error\nInvalid map\n");
		exit(1);
	}
}

static void	flood_fill_move(char **str, t_info *info, int dx, int dy)
{
	int	x;
	int	y;

	x = (int)info->pos.x;
	y = (int)info->pos.y;
	if (str[y + dy][x + dx] != '1')
	{
		info->pos.x += dx;
		info->pos.y += dy;
		info->depth += 1;
		flood_fill(str, info);
		info->pos.x -= dx;
		info->pos.y -= dy;
	}
}

void	flood_fill(char **str, t_info *info)
{
	int	x;
	int	y;

	x = (int)info->pos.x;
	y = (int)info->pos.y;
	check_flood_fill_bounds(str, info);
	if (info->depth > 80000)
	{
		free_info(info);
		free_tab(str);
		exit(1);
	}
	str[y][x] = '1';
	flood_fill_move(str, info, -1, 0);
	flood_fill_move(str, info, 0, 1);
	flood_fill_move(str, info, 1, 0);
	flood_fill_move(str, info, 0, -1);
}
