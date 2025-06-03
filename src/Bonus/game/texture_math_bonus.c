/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_math_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:24:27 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static float	calculate_texture_step(mlx_texture_t *texture, int line_height)
{
	return ((float)texture->height / (float)line_height);
}

static int	calculate_texture_x(t_info *info, t_ray *ray, mlx_texture_t *tex)
{
	float	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = info->pos.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = info->pos.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static int	get_texture_pixel(mlx_texture_t *tex, int x, int y)
{
	uint8_t	*r;

	r = tex->pixels + (y * tex->width + x) * 4;
	return ((r[0] << 24) | (r[1] << 16) | (r[2] << 8) | r[3]);
}

static int	get_tex_color(mlx_texture_t *tex, int tex_x, float tex_pos)
{
	int	tex_y;

	tex_y = (int)tex_pos & (tex->height - 1);
	return (get_texture_pixel(tex, tex_x, tex_y));
}

void	draw_texture_column(t_info *info, t_ray *ray, int x)
{
	mlx_texture_t	*tex;
	int				tex_x;
	float			step;
	float			tex_pos;
	int				y;

	tex = select_wall_texture(info, ray);
	tex_x = calculate_texture_x(info, ray, tex);
	step = calculate_texture_step(tex, ray->line_height);
	if (ray->real_draw_start < 0)
		tex_pos = -ray->real_draw_start * step;
	else
		tex_pos = (ray->real_draw_start - HEIGHT / 2 + ray->line_height / 2)
			* step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel(info, x, y, get_tex_color(tex, tex_x, tex_pos));
		tex_pos += step;
		y++;
	}
}
