/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:19:57 by kichlee           #+#    #+#             */
/*   Updated: 2023/11/05 16:44:15 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_direction(t_monitor *monitor)
{
	if (monitor->key.left == TRUE)
		rotate_update(monitor, 0.05);
	if (monitor->key.right == TRUE)
		rotate_update(monitor, -0.05);
}

void	rotate_update(t_monitor *monitor, double degree)
{
	rotate_vector(&monitor->player.dir, degree);
	rotate_vector(&monitor->rc.camera, degree);
}

void	rotate_vector(t_vec *vector, double degree)
{
	double	temp;

	temp = vector->x;
	vector->x = (vector->x * cos(degree)) - (vector->y * sin(degree));
	vector->y = (temp * sin(degree)) + (vector->y * cos(degree));
}
