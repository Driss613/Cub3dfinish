/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:22:46 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:20:25 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

static int	init_game_struct(t_info *info)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr("Error\nMemory allocation failed\n");
		return (1);
	}
	info->game = game;
	return (0);
}

static void	setup_mlx_hooks(t_game *game, t_info *info)
{
	mlx_key_hook(game->mlx, key_hook, info);
	mlx_loop_hook(game->mlx, ft_raycasting, info);
}

void	launch_game(t_info *info)
{
	if (init_game_struct(info))
		return ;
	info->map_height = get_map_height(info->map);
	info->map_width = get_map_width(info->map, info->map_height);
	if (init_mlx_context(info))
	{
		if (info->game->mlx)
			mlx_terminate(info->game->mlx);
		return ;
	}
	if (init_textures(info->game, info))
	{
		mlx_delete_image(info->game->mlx, info->game->img);
		mlx_terminate(info->game->mlx);
		return ;
	}
	setup_mlx_hooks(info->game, info);
	mlx_loop(info->game->mlx);
	mlx_delete_image(info->game->mlx, info->game->img);
	free_textures(info);
	mlx_terminate(info->game->mlx);
}
