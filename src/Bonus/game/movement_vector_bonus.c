/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_vector_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:44:06 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	get_movement_vector(t_info *info, int key, float *dx, float *dy)
{
	if (key == MLX_KEY_W)
	{
		*dx = info->pos.dir_x * 0.03f;
		*dy = info->pos.dir_y * 0.03f;
	}
	else if (key == MLX_KEY_S)
	{
		*dx = -info->pos.dir_x * 0.03f;
		*dy = -info->pos.dir_y * 0.03f;
	}
	else if (key == MLX_KEY_A)
	{
		*dx = info->pos.dir_y * 0.03f;
		*dy = -info->pos.dir_x * 0.03f;
	}
	else if (key == MLX_KEY_D)
	{
		*dx = -info->pos.dir_y * 0.03f;
		*dy = info->pos.dir_x * 0.03f;
	}
}
