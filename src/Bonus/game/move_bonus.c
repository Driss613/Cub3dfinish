/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:41:56 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static float	collision_check_pos(float current, float new_pos, float margin)
{
	if (new_pos > current)
		return (new_pos + margin);
	else
		return (new_pos - margin);
}

static void	try_move(t_info *info, float new_x, float new_y, float margin)
{
	float	test_x;
	float	test_y;

	test_x = collision_check_pos(info->pos.x, new_x, margin);
	test_y = collision_check_pos(info->pos.y, new_y, margin);
	if (info->map[(int)(info->pos.y)][(int)test_x] != '1')
		info->pos.x = new_x;
	if (info->map[(int)test_y][(int)(info->pos.x)] != '1')
		info->pos.y = new_y;
}

void	ft_move(t_info *info)
{
	float	margin;
	int		keys[4];
	float	dx;
	float	dy;
	int		i;

	margin = 0.1f;
	i = 0;
	keys[0] = MLX_KEY_W;
	keys[1] = MLX_KEY_S;
	keys[2] = MLX_KEY_A;
	keys[3] = MLX_KEY_D;
	while (i < 4)
	{
		if (mlx_is_key_down(info->game->mlx, keys[i]))
		{
			get_movement_vector(info, keys[i], &dx, &dy);
			try_move(info, info->pos.x + dx, info->pos.y + dy, margin);
		}
		i++;
	}
}
