/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:39:22 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:21:30 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

void	ft_raycasting(void *param)
{
	t_info	*info;
	t_ray	ray;
	int		x;

	info = (t_info *)param;
	x = 0;
	ft_move(info);
	ft_camera(info);
	while (x < WIDTH)
	{
		init_ray(&ray, info, x);
		calc_step_and_side_dist(&ray, info);
		perform_dda(&ray, info);
		calc_perp_wall_dist(&ray, info);
		calc_line_height(&ray);
		draw_wall_column(info, &ray, x);
		x++;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_info	*info;
	t_game	*game;

	info = (t_info *)param;
	game = info->game;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(info->game->mlx, info->game->img);
		free_textures(info);
		mlx_terminate(game->mlx);
		free_info(info);
		exit(0);
	}
}
