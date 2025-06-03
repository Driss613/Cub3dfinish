/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:38:23 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:22 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d_bonus.h"

void	parsing_file(char *argv)
{
	char	buffer[1];
	int		fd;
	size_t	byte_read;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error\nCannot open file\n");
		exit(1);
	}
	byte_read = read(fd, buffer, 1);
	close(fd);
	if (byte_read <= 0)
	{
		ft_putstr("Error\nFile is empty\n");
		exit(1);
	}
}
