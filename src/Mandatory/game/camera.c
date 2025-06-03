/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:46:07 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 09:36:30 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

static void	rotate(t_info *info, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->pos.dir_x;
	old_plane_x = info->pos.plane_x;
	info->pos.dir_x = info->pos.dir_x * cos(angle) - info->pos.dir_y
		* sin(angle);
	info->pos.dir_y = old_dir_x * sin(angle) + info->pos.dir_y
		* cos(angle);
	info->pos.plane_x = info->pos.plane_x * cos(angle) - info->pos.plane_y
		* sin(angle);
	info->pos.plane_y = old_plane_x * sin(angle) + info->pos.plane_y
		* cos(angle);
}

void	ft_camera(t_info *info)
{
	if (mlx_is_key_down(info->game->mlx, MLX_KEY_RIGHT))
		rotate(info, 0.02);
	if (mlx_is_key_down(info->game->mlx, MLX_KEY_LEFT))
		rotate(info, -0.02);
}
