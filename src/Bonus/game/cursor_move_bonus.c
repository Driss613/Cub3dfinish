/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:45:13 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static void	rotate_view(t_pos *pos, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pos->dir_x;
	pos->dir_x = old_dir_x * cos(angle) - pos->dir_y * sin(angle);
	pos->dir_y = old_dir_x * sin(angle) + pos->dir_y * cos(angle);
	old_plane_x = pos->plane_x;
	pos->plane_x = old_plane_x * cos(angle) - pos->plane_y * sin(angle);
	pos->plane_y = old_plane_x * sin(angle) + pos->plane_y * cos(angle);
}

void	ft_cursor_move(t_info *info)
{
	t_game	*game;
	float	speed;
	int		current_mouse_x;
	int		current_mouse_y;
	double	delta_x;

	game = info->game;
	speed = 0.001;
	if (game->mouse_locked)
	{
		mlx_get_mouse_pos(game->mlx, &current_mouse_x, &current_mouse_y);
		delta_x = current_mouse_x - game->last_mouse_x;
		if (delta_x != 0)
			rotate_view(&info->pos, delta_x * speed);
		mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
		game->last_mouse_x = WIDTH / 2;
	}
}
