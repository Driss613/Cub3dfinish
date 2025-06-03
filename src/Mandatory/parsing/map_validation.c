/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:43:34 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 09:36:30 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

static void	check_player_pos(t_info *info, int counter)
{
	if (counter == 0 || counter > 1)
	{
		free_info(info);
		ft_putstr(
			"Error\nThe character must have only one position in the map\n");
		exit(1);
	}
}

void	verif_map(t_info *info)
{
	int	i;
	int	j;
	int	counter;

	j = 0;
	counter = 0;
	while (info->map[j])
	{
		i = 0;
		while (info->map[j][i])
		{
			if (info->map[j][i] == 'N' || info->map[j][i] == 'S'
				|| info->map[j][i] == 'E' || info->map[j][i] == 'W')
			{
				info->pos.x = i + 0.5;
				info->pos.y = j + 0.5;
				counter++;
			}
			i++;
		}
		j++;
	}
	check_player_pos(info, counter);
}

void	copy_map2(char ***str, t_info *info, int countline)
{
	int	i;

	i = 0;
	*str = malloc(sizeof(char *) * (countline + 1));
	if (!*str)
	{
		free_info(info);
		exit(1);
	}
	while (info->map[i])
	{
		(*str)[i] = ft_strdup(info->map[i]);
		if (!(*str)[i])
		{
			free_tab((*str));
			free_info(info);
			exit(1);
		}
		i++;
	}
	(*str)[i] = NULL;
}
