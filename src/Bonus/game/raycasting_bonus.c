/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:49:48 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	init_ray(t_ray *ray, t_info *info, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = info->pos.dir_x + info->pos.plane_x * ray->camera_x;
	ray->ray_dir_y = info->pos.dir_y + info->pos.plane_y * ray->camera_x;
	ray->map_x = (int)info->pos.x;
	ray->map_y = (int)info->pos.y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	calc_step_and_side_dist(t_ray *ray, t_info *info)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (info->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - info->pos.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (info->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - info->pos.y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_info *info)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_y >= info->map_height || ray->map_x < 0
			|| ray->map_x >= (int)ft_strlen(info->map[ray->map_y]))
			break ;
		if (info->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calc_perp_wall_dist(t_ray *ray, t_info *info)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - info->pos.x + (1 - ray->step_x)
				/ 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - info->pos.y + (1 - ray->step_y)
				/ 2.0) / ray->ray_dir_y;
}

void	calc_line_height(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->real_draw_start = -ray->line_height / 2 + HEIGHT / 2;
	ray->draw_start = ray->real_draw_start;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}
