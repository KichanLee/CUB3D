/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:25 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 16:27:06 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initailze(t_monitor *monitor)
{
	monitor->window.mlx = mlx_init();
	if (monitor->window.mlx == 0)
		exception_handler(err_general);
	monitor->window.win = mlx_new_window(monitor->window.mlx,
			640, 480, "cub3d");
	if (monitor->window.win == 0)
		exception_handler(err_general);
	mlx_hook(monitor->window.win, EVENT_KEY_PRESS, 0, \
				&press_event_handler, &monitor->key);
	mlx_hook(monitor->window.win, EVENT_KEY_RELEASE, 0, \
				&release_event_handler, &monitor->key);
	mlx_hook(monitor->window.win, EVENT_KEY_EXIT, 0, \
				&exit_event_handler, &monitor->key);
}

void	free_arr(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}
