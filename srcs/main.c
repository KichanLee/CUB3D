/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:13 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 15:55:57 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_monitor	monitor;
	t_map		*map;

	if (argc != 2)
		exception_handler(err_arg);
	initailze(&monitor);
	map = create_map(argv[1]);
	initalize_setting(&monitor, map);
	mlx_loop_hook(monitor.window.mlx, &rendering_image, &monitor);
	mlx_loop(monitor.window.mlx);
	return (0);
}
