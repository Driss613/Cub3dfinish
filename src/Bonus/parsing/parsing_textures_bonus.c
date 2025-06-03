/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:39:28 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

int	cut_info(char *str, char **info)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i] || str[i] == '\n')
	{
		ft_putstr("Error\nInvalid texture or color configuration\n");
		return (1);
	}
	j = i + 2;
	while (str[j] && str[j] != '\n' && str[j] != ' ')
		j++;
	*info = ft_substr(str, i + 2, j - (i + 2));
	if (!(*info))
	{
		ft_putstr("Error\nMemory allocation failed\n");
		return (1);
	}
	return (0);
}

int	take_info(char *copymap, char *str, char **info)
{
	int	length;

	length = ft_strlen(str);
	if (!ft_strncmp(copymap, str, length) && copymap[length] == ' ')
	{
		if (*info)
		{
			ft_putstr("Error\nTexture cannot be redefined\n");
			return (1);
		}
		if (cut_info(&copymap[length - 1], info))
			return (1);
		else
			return (2);
	}
	return (0);
}

int	take_infos(char *copymap, t_info *info)
{
	int		i;
	int		index;
	char	**infos[6];
	char	*texture[6];
	int		return_value;

	i = 0;
	index = 0;
	if (copymap[i] == '\n')
		return (0);
	while (copymap[i] == ' ')
		i++;
	if (copymap[i] == '\n')
		return (0);
	init_tab_infos(infos, info, texture);
	while (index < 6)
	{
		return_value = take_info(&copymap[i], texture[index], infos[index]);
		if (return_value == 1)
			return (1);
		else if (return_value == 2)
			return (0);
		index++;
	}
	return (1);
}
