/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:23:56 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	put_pixel(t_info *info, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(info->game->img, x, y, color);
}

static void	draw_ceiling(t_info *info, int x, int start)
{
	int	y;

	y = 0;
	while (y < start)
	{
		put_pixel(info, x, y, info->ceiling_color);
		y++;
	}
}

static void	draw_floor(t_info *info, int x, int start)
{
	while (start < HEIGHT)
	{
		put_pixel(info, x, start, info->floor_color);
		start++;
	}
}

void	draw_wall_column(t_info *info, t_ray *ray, int x)
{
	draw_ceiling(info, x, ray->draw_start);
	draw_texture_column(info, ray, x);
	draw_floor(info, x, ray->draw_end);
}
