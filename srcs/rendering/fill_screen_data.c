/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:47 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 19:13:53 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	making_screen(t_monitor *monitor,
			int x, double per_wall_distance, int side);
void	get_64(int line_height, int *draw_range);
int		get_tex_x(t_monitor *monitor, double per_wall_distance, int side);
void	fill_screen_data_bg(int *data, int x, \
						unsigned long long f_rgb, unsigned long long c_rgb);
int		get_color(t_monitor *monitor, int tex_y, int tex_x, int side);

void	making_screen(t_monitor *monitor,
			int x, double per_wall_distance, int side)
{
	int		line_height;
	int		draw_range[2];
	double	step;
	double	tex_pos;
	int		y;

	line_height = (int)(480 / per_wall_distance);
	get_64(line_height, draw_range);
	step = 1.0 * 64 / line_height;
	tex_pos = (draw_range[0] - 480 / 2 + line_height / 2) * step;
	fill_screen_data_bg(monitor->screen.data, x,
		monitor->f_rgb, monitor->c_rgb);
	y = draw_range[0];
	while (y < draw_range[1])
	{
		tex_pos += step;
		monitor->screen.data[y * 640 + x] = get_color(monitor,
				(int)tex_pos & (64 - 1),
				get_tex_x(monitor, per_wall_distance, side),
				side);
		y++;
	}
}

void	get_64(int line_height, int *range_draw)
{
	range_draw[0] = (-line_height / 2) + (480 / 2);
	range_draw[1] = (line_height / 2) + (480 / 2);
	if (range_draw[0] < 0)
		range_draw[0] = 0;
	if (range_draw[1] > 480)
		range_draw[1] = 480;
}

int	get_tex_x(t_monitor *monitor, double per_wall_distance, int side)
{
	int		tex_x;
	double	wall_x;

	if (side == 0)
		wall_x = monitor->player.pos.y
			+ per_wall_distance * monitor->rc.ray.ray_dir.y;
	else
		wall_x = monitor->player.pos.x
			+ per_wall_distance * monitor->rc.ray.ray_dir.x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * 64.0);
	if ((side == 0 && monitor->rc.ray.ray_dir.x > 0)
		|| (side == 1 && monitor->rc.ray.ray_dir.y < 0))
		tex_x = 64 - tex_x - 1;
	return (tex_x);
}

void	fill_screen_data_bg(\
		int *data, int x, unsigned long long f_rgb, unsigned long long c_rgb)
{
	int	y;

	y = 0;
	while (y < 480 / 2)
	{
		data[y * 640 + x] = c_rgb;
		data[(480 - y - 1) * 640 + x] = f_rgb;
		y++;
	}
}

int	get_color(t_monitor *monitor, int tex_y, int tex_x, int side)
{
	int	color;

	if (side == 0 && monitor->rc.ray.ray_dir.x >= 0)
		color = monitor->textures[we].data[64 * tex_y + tex_x];
	else if (side == 0 && monitor->rc.ray.ray_dir.x < 0)
		color = monitor->textures[ea].data[64 * tex_y + tex_x];
	else if (side == 1 && monitor->rc.ray.ray_dir.y >= 0)
		color = monitor->textures[so].data[64 * tex_y + tex_x];
	else
		color = monitor->textures[no].data[64 * tex_y + tex_x];
	return (color);
}
