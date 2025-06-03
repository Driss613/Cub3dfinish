/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:41:29 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

int	calculate_minimap_scale(int window_width, int window_height, int map_width,
		int map_height)
{
	int	max_scale_y;
	int	scale;
	int	max_scale_x;

	max_scale_x = window_width / (map_width + 2);
	max_scale_y = window_height / (map_height + 2);
	if (max_scale_x < max_scale_y)
		scale = max_scale_x;
	else
		scale = max_scale_y;
	if (scale < 2)
		scale = 2;
	return (scale);
}

void	draw_rect_filled(mlx_image_t *img, int pos[2], int scale,
		uint32_t color)
{
	int	i;
	int	j;
	int	px;
	int	py;

	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			px = pos[0] + i;
			py = pos[1] + j;
			if (px >= 0 && py >= 0 && px < (int)img->width
				&& py < (int)img->height)
				mlx_put_pixel(img, px, py, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_info *info, mlx_image_t *img, int scale)
{
	uint32_t	color;
	int			y;
	int			x;
	int			pos[2];

	y = 0;
	while (y < info->map_height)
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == '1')
				color = 0x1A1A1AFF;
			else
				color = 0xCCCCCCFF;
			pos[0] = x * scale;
			pos[1] = y * scale;
			if (info->map[y][x] == '1' || info->map[y][x] == '0'
				|| info->map[y][x] == ' ')
				draw_rect_filled(img, pos, scale, color);
			x++;
		}
		y++;
	}
}
