/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 07:48:13 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:21:11 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

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
	return (0);
}
