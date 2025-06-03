/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:39:23 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 09:36:30 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3d.h"

void	parsing_arguments(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Error\nIncorrect number of arguments\n");
		exit(1);
	}
}

void	parsing_extension(char *argv)
{
	char	*extension;

	if (!argv || ft_strlen(argv) < 4)
	{
		ft_putstr("Error\nInvalid file extension\n");
		exit(1);
	}
	extension = ft_strrchr(argv, '.');
	if (!extension || ft_strcmp(extension, ".cub"))
	{
		ft_putstr("Error\nInvalid file extension\n");
		exit(1);
	}
}
