/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:34:01 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 19:17:13 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_map		t_map;
typedef struct s_monitor	t_monitor;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_xy
{
	double	x;
	double	y;
}	t_xy;

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

/* mlx 구조체 */
typedef struct s_win {
	void	*mlx;
	void	*win;
}	t_window;

/* images */
typedef struct s_image {
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}t_image;

typedef struct s_ray
{
	t_vec		ray_dir;
	t_vec		side_dist;
	t_vec		delta_dist;
	t_xy		step;
}	t_ray;

typedef struct s_raycasting
{
	t_vec		camera;
	t_ray		ray;
}	t_raycasting;

typedef enum e_id
{
	invalid = -1,
	we,
	so,
	no,
	ea,
	id_f,
	id_c
}t_id;

typedef struct s_map
{
	char					**contents;
	char					*elements[6];
	unsigned long long		f_rgb;
	unsigned long long		c_rgb;
	int						width;
	int						height;
	int						start_x;
	int						start_y;
	int						start_dir;
}	t_map;

typedef enum e_err
{
	err_arg = 1,
	err_file,
	err_id,
	err_img,
	err_rgb,
	err_map,
	err_wall,
	err_player,
	err_general
}	t_err;

typedef struct s_player {
	t_xy		pos;
	t_vec		dir;
	t_xy		map_pos;
}	t_player;

typedef struct s_key {
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_bool	left;
	t_bool	right;
}t_key;

typedef struct s_monitor {
	unsigned long long		f_rgb;
	unsigned long long		c_rgb;
	char					**map;
	t_key					key;
	t_window				window;
	t_image					screen;
	t_image					textures[4];
	t_player				player;
	t_raycasting			rc;
}	t_monitor;

#endif