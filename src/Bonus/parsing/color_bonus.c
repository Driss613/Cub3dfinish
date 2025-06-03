/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:57:12 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

static char	*extract_rgb(char *argv, int limit, t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (limit + 1));
	if (!tmp)
	{
		free_info(info);
		exit(1);
	}
	while (i < limit)
	{
		tmp[i] = argv[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int	search_rgb(char *argv, int *i)
{
	while (argv[*i] && argv[*i] != ',')
	{
		if (!ft_isdigit(argv[*i]))
			return (1);
		(*i)++;
	}
	return (0);
}

static int	validate_and_convert_rgb(t_info *info, char *argv)
{
	int		i;
	int		hold_i;
	int		j;
	int		rgb[3];
	char	*tmp;

	j = 0;
	i = 0;
	while (argv[i])
	{
		hold_i = i;
		if (search_rgb(argv, &i))
			return (-1);
		tmp = extract_rgb(&argv[hold_i], i - hold_i, info);
		rgb[j] = ft_atoi(tmp);
		free(tmp);
		if (rgb[j] < 0 || rgb[j] > 255)
			return (-1);
		if (argv[i])
			i++;
		j++;
	}
	if (j != 3)
		return (-1);
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 255);
}

int	set_rgb_color(t_info *info, char c)
{
	int	color;

	if (c == 'f')
	{
		color = validate_and_convert_rgb(info, info->f);
		info->floor_color = color;
	}
	else
	{
		color = validate_and_convert_rgb(info, info->c);
		info->ceiling_color = color;
	}
	if (color == -1)
	{
		ft_putstr("Error\nInvalid RGB configuration\n");
		free_info(info);
		exit(1);
	}
	return (0);
}
