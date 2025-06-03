/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:31:45 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	parsing_map(char *argv, t_info *info)
{
	int		fd;
	int		countline;
	char	**str;
	int		skipline;

	countline = 0;
	fd = open(argv, O_RDONLY);
	skipline = check_map(fd, info);
	skipline += stock_map(fd, info, &countline);
	close(fd);
	fd = open(argv, O_RDONLY);
	copy_map(fd, info, countline, skipline);
	close(fd);
	verif_map(info);
	init_orientation(info);
	copy_map2(&str, info, countline);
	info->depth = 0;
	flood_fill(str, info);
	free_tab(str);
}

static void	check_image_exist(t_info *info, char *img)
{
	int	fd;

	fd = open(img, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\nAn image no longer exists\n");
		free_info(info);
		exit(1);
	}
	close(fd);
}

void	parsing(int argc, char **argv, t_info *info)
{
	parsing_arguments(argc);
	parsing_extension(argv[1]);
	parsing_file(argv[1]);
	parsing_map(argv[1], info);
	check_image_exist(info, info->we);
	check_image_exist(info, info->no);
	check_image_exist(info, info->so);
	check_image_exist(info, info->ea);
	set_rgb_color(info, 'f');
	set_rgb_color(info, 'c');
}
