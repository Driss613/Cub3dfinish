/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:39:22 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	ft_raycasting(void *param)
{
	t_info	*info;
	t_ray	ray;
	int		x;

	info = (t_info *)param;
	x = 0;
	ft_move(info);
	ft_cursor_move(info);
	ft_camera(info);
	while (x < WIDTH)
	{
		init_ray(&ray, info, x);
		calc_step_and_side_dist(&ray, info);
		perform_dda(&ray, info);
		calc_perp_wall_dist(&ray, info);
		calc_line_height(&ray);
		draw_wall_column(info, &ray, x);
		info->game->player_img->instances[0].x = (int)(info->pos.x
				* info->game->scale_minimap);
		info->game->player_img->instances[0].y = (int)(info->pos.y
				* info->game->scale_minimap);
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
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
	{
		game->mouse_locked = !game->mouse_locked;
		if (game->mouse_locked)
		{
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
			mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
			game->last_mouse_x = WIDTH / 2;
		}
		else
			mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	}
}
