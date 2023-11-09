/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:19 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 19:22:26 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_monitor *monitor);
void	hr_move_h_update(char **map, \
				t_player *player, int new_dir_x, int new_dir_y);
void	vt_move_update(char **map, \
				t_player *player, int new_dir_x, int new_dir_y);
void	rotate_update(t_monitor *monitor, double radian);
void	turn_direction(t_monitor *monitor);
void	rotate_vector(t_vec *vector, double theta);
void	move_wasd(t_monitor *monitor);

void	move_player(t_monitor *monitor)
{
	move_wasd(monitor);
	turn_direction(monitor);
}

void	move_wasd(t_monitor *monitor)
{
	if (monitor->key.w)
		hr_move_h_update(monitor->map, &monitor->player, 1, 1);
	if (monitor->key.s)
		hr_move_h_update(monitor->map, &monitor->player, -1, -1);
	if (monitor->key.a)
		vt_move_update(monitor->map, &monitor->player, 1, -1);
	if (monitor->key.d == TRUE)
		vt_move_update(monitor->map, &monitor->player, -1, 1);
}

void	hr_move_h_update(char **map,
			t_player *player, int new_dir_x, int new_dir_y)
{
	t_xy		*pos;
	double		dir_x;
	double		dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)(pos->y + dir_y * (0.05 + 0.000000001))][(int)pos->x] != '1')
		pos->y += dir_y * 0.05;
	if (map[(int)pos->y][(int)(pos->x + dir_x * (0.05 + 0.000000001))] != '1')
		pos->x += dir_x * 0.05;
}

void	vt_move_update(char **map,
			t_player *player, int new_dir_x, int new_dir_y)
{
	double		dir_x;
	double		dir_y;
	t_xy		*pos;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)(pos->y + dir_x * (0.05 + 0.000000001))][(int)pos->x] != '1')
		pos->y += dir_x * 0.05;
	if (map[(int)pos->y][(int)(pos->x + dir_y * (0.05 + 0.000000001))] != '1')
		pos->x += dir_y * 0.05;
}
