/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:02 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 15:26:46 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rendering_image(t_monitor *monitor)
{
	move_player(monitor);
	raycasting_image(monitor);
	mlx_put_image_to_window(monitor->window.mlx,
		monitor->window.win, monitor->screen.img, 0, 0);
	return (0);
}
