/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:36:28 by kichlee           #+#    #+#             */
/*   Updated: 2023/11/05 19:06:34 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initalize_mapcolor(t_monitor *monitor, t_map *map)
{
	monitor->map = map->contents;
	monitor->f_rgb = map->f_rgb;
	monitor->c_rgb = map->c_rgb;
}

void	initalize_setting_a_texture(t_image *texture,
				void *mlx, char *path)
{
	texture->img
		= mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	if (!texture->img)
		exception_handler(err_img);
	texture->data = (int *)mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->size_line, &texture->endian);
}

void	initalize_setting_textures(t_monitor *monitor, char *elements[6])
{
	t_image	*textures;
	void	*mlx;
	int		x;

	mlx = monitor->window.mlx;
	textures = monitor->textures;
	x = -1;
	while (++x < 4)
		initalize_setting_a_texture(&textures[x], mlx, elements[x]);
}
