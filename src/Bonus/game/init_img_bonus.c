/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 07:48:13 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static int	init_map_img(t_info *info)
{
	info->game->img = mlx_new_image(info->game->mlx, WIDTH, HEIGHT);
	if (!info->game->img)
	{
		ft_putstr("Error\nFailed to create MLX image\n");
		return (1);
	}
	if (mlx_image_to_window(info->game->mlx, info->game->img, 0, 0) < 0)
	{
		ft_putstr("Error\nFailed to display image\n");
		mlx_delete_image(info->game->mlx, info->game->img);
		return (1);
	}
	return (0);
}

static int	init_minimap_img(t_info *info)
{
	int	scale;

	scale = calculate_minimap_scale(200, 200, info->map_width,
			info->map_height);
	info->game->scale_minimap = scale;
	info->game->minimap_img = mlx_new_image(info->game->mlx, info->map_width
			* scale, info->map_height * scale);
	if (!info->game->minimap_img)
	{
		ft_putstr("Error\nFailed to create minimap image\n");
		return (1);
	}
	if (mlx_image_to_window(info->game->mlx, info->game->minimap_img, 0, 0) < 0)
	{
		ft_putstr("Error\nFailed to display minimap image\n");
		mlx_delete_image(info->game->mlx, info->game->img);
		mlx_delete_image(info->game->mlx, info->game->minimap_img);
		return (1);
	}
	return (0);
}

static int	init_player_img(t_info *info)
{
	int	x;
	int	y;

	info->game->player_img = mlx_new_image(info->game->mlx, 5, 5);
	if (!info->game->player_img)
	{
		ft_putstr("Error\nFailed to create player image\n");
		return (1);
	}
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			mlx_put_pixel(info->game->player_img, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(info->game->mlx, info->game->player_img, info->pos.x
			* info->game->scale_minimap, info->pos.y
			* info->game->scale_minimap) < 0)
		return (1);
	return (0);
}

int	init_mlx_context(t_info *info)
{
	info->game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!info->game->mlx)
	{
		ft_putstr("Error\nFailed to initialize MLX42\n");
		return (1);
	}
	if (init_map_img(info))
		return (1);
	if (init_minimap_img(info))
		return (1);
	if (init_player_img(info))
	{
		ft_putstr("Error\nFailed to display player image\n");
		mlx_delete_image(info->game->mlx, info->game->player_img);
		mlx_delete_image(info->game->mlx, info->game->img);
		mlx_delete_image(info->game->mlx, info->game->minimap_img);
		return (1);
	}
	draw_minimap(info, info->game->minimap_img, info->game->scale_minimap);
	return (0);
}
