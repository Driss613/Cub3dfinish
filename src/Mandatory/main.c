/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:35:32 by drabarza          #+#    #+#             */
/*   Updated: 2025/06/02 10:02:51 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;

	init_info(&info);
	parsing(argc, argv, &info);
	launch_game(&info);
	free_info(&info);
	return (0);
}
