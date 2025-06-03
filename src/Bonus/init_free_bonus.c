/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:09:46 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:53 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	init_info(t_info *info)
{
	info->game = NULL;
	info->map = NULL;
	info->no = NULL;
	info->so = NULL;
	info->we = NULL;
	info->ea = NULL;
	info->f = NULL;
	info->c = NULL;
	info->pos.fov = 0.66;
	info->pos.angle = 0;
}

void	init_tab_infos(char ***infos, t_info *info, char **texture)
{
	infos[0] = &info->no;
	infos[1] = &info->so;
	infos[2] = &info->we;
	infos[3] = &info->ea;
	infos[4] = &info->f;
	infos[5] = &info->c;
	texture[0] = "NO";
	texture[1] = "SO";
	texture[2] = "WE";
	texture[3] = "EA";
	texture[4] = "F";
	texture[5] = "C";
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_info(t_info *info)
{
	if (info->game)
		free(info->game);
	if (info->map)
		free_tab(info->map);
	if (info->no)
		free(info->no);
	if (info->so)
		free(info->so);
	if (info->we)
		free(info->we);
	if (info->ea)
		free(info->ea);
	if (info->f)
		free(info->f);
	if (info->c)
		free(info->c);
}

void	init_orientation(t_info *info)
{
	int	x;
	int	y;

	x = (int)info->pos.x;
	y = (int)info->pos.y;
	if (info->map[y][x] == 'N')
		info->pos.angle = 3 * M_PI / 2;
	if (info->map[y][x] == 'E')
		info->pos.angle = 0;
	if (info->map[y][x] == 'S')
		info->pos.angle = M_PI / 2;
	if (info->map[y][x] == 'W')
		info->pos.angle = M_PI;
	info->pos.dir_x = cos(info->pos.angle);
	info->pos.dir_y = sin(info->pos.angle);
	info->pos.plane_x = -sin(info->pos.angle) * info->pos.fov;
	info->pos.plane_y = cos(info->pos.angle) * info->pos.fov;
	info->map[(int)info->pos.y][(int)info->pos.x] = '0';
}
