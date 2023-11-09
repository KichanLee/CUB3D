/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:28:53 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 19:27:21 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_monitor *monitor);
void	init_ray(t_ray *ray, t_player *player, t_vec camera, double camera_x);
double	calculate_delta_dist(double ray_dir);
int		get_hit_side(t_raycasting *rc, t_player *player, char **map);

void	raycasting_image(t_monitor *monitor)
{
	int				x;
	int				side;
	double			perp_wall_dist;
	t_raycasting	*ray;
	t_player		*player;

	x = 0;
	ray = &monitor->rc;
	player = &monitor->player;
	while (x < 640)
	{
		monitor->player.map_pos.x = (int)monitor->player.pos.x;
		monitor->player.map_pos.y = (int)monitor->player.pos.y;
		init_ray(&ray->ray, player,
			ray->camera, (2 * x / (double)640 - 1));
		side = get_hit_side(ray, player, monitor->map);
		if (side == 0)
			perp_wall_dist = ray->ray.side_dist.x - ray->ray.delta_dist.x;
		else
			perp_wall_dist = ray->ray.side_dist.y - ray->ray.delta_dist.y;
		making_screen(monitor, x, perp_wall_dist, side);
		x++;
	}
}

double	calculate_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	else
		return (fabs(1 / ray_dir));
}

void	init_ray(t_ray *ray,
				t_player *pl, t_vec camera, double camera_x)
{
	ray->ray_dir.x = pl->dir.x + (camera.x * camera_x);
	ray->ray_dir.y = pl->dir.y + (camera.y * camera_x);
	ray->delta_dist.x = calculate_delta_dist(ray->ray_dir.x);
	ray->delta_dist.y = calculate_delta_dist(ray->ray_dir.y);
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pl->pos.x - pl->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (pl->map_pos.x + 1 - pl->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pl->pos.y - pl->map_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (pl->map_pos.y + 1 - pl->pos.y) * ray->delta_dist.y;
	}
}

int	get_hit_side(t_raycasting *rc, t_player *player, char **map)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (rc->ray.side_dist.x < rc->ray.side_dist.y)
		{
			rc->ray.side_dist.x += rc->ray.delta_dist.x;
			player->map_pos.x += rc->ray.step.x;
			side = 0;
		}
		else
		{
			rc->ray.side_dist.y += rc->ray.delta_dist.y;
			player->map_pos.y += rc->ray.step.y;
			side = 1;
		}
		if (map[(int)player->map_pos.y][(int)player->map_pos.x] == '1')
			hit = 1;
	}
	return (side);
}
