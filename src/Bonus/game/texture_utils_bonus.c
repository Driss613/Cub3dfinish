/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:24:20 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

mlx_texture_t	*select_wall_texture(t_info *info, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (info->game->textures[2]);
		else
			return (info->game->textures[3]);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (info->game->textures[1]);
		else
			return (info->game->textures[0]);
	}
	return (NULL);
}

void	free_textures(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (info->game->textures[i])
		{
			mlx_delete_texture(info->game->textures[i]);
			info->game->textures[i] = NULL;
		}
		i++;
	}
}

int	init_textures(t_game *game, t_info *info)
{
	game->textures[0] = mlx_load_png(info->no);
	game->textures[1] = mlx_load_png(info->so);
	game->textures[2] = mlx_load_png(info->ea);
	game->textures[3] = mlx_load_png(info->we);
	if (!game->textures[0] || !game->textures[1] || !game->textures[2]
		|| !game->textures[3])
	{
		ft_putstr("Error\nFailed to load a texture\n");
		free_textures(info);
		return (1);
	}
	return (0);
}
