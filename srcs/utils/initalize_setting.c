/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:31 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 19:19:17 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initalize_setting(t_monitor *monitor, t_map *map);
void	initalize_setting_player(t_player *player, t_map *map);
void	initalize_setting_key(t_key *key);
void	initalize_screen(t_monitor *monitor);

void	initalize_setting(t_monitor *monitor, t_map *map)
{
	initalize_mapcolor(monitor, map);
	initalize_setting_textures(monitor, map->elements);
	initalize_setting_player(&monitor->player, map);
	initalize_setting_key(&monitor->key);
	initalize_screen(monitor);
}

void	initalize_screen(t_monitor *monitor)
{
	monitor->rc.camera.x = monitor->player.dir.y * (0.66);
	monitor->rc.camera.y = monitor->player.dir.x * (-0.66);
	monitor->screen.img
		= mlx_new_image(monitor->window.mlx, 640, 480);
	if (monitor->screen.img == 0)
		exception_handler(err_general);
	monitor->screen.data = (int *)mlx_get_data_addr(monitor->screen.img,
			&monitor->screen.bpp,
			&monitor->screen.size_line,
			&monitor->screen.endian);
}

void	initalize_setting_player(t_player *player, t_map *map)
{
	player->pos.x = map->start_x + 0.5;
	player->pos.y = map->start_y + 0.5;
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
	if (map->start_dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (map->start_dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (map->start_dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (map->start_dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

void	initalize_setting_key(t_key *button)
{
	button->w = FALSE;
	button->a = FALSE;
	button->s = FALSE;
	button->d = FALSE;
	button->left = FALSE;
	button->right = FALSE;
}
