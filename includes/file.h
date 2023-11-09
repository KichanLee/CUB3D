/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:33:41 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 19:13:14 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "cub3d.h"
# include "../libft/includes/libft.h"

/*utils*/
void	initailze(t_monitor *monitor);
void	exception_handler(t_err errno);
int		exit_event_handler(int key_code, void *param);
int		press_event_handler(int key_code, t_key *key);
int		release_event_handler(int key_code, t_key *key);
void	free_arr(char **arr);
void	initalize_setting(t_monitor *monitor, t_map *map);
void	move_player(t_monitor *monitor);

/*map*/
t_map	*create_map(char *file);
void	check_extension(char *file);
void	file_down(t_list **head, char *file);
t_list	*split_file(t_list *lst_4_map);
void	parse_map(t_map *map, t_list *lst_4_map);
void	check_map(t_map *map);
void	check_closed_wall(t_map *map);
void	set_rgb(t_map *map);
t_bool	check_empty_line(char *line);

/*rendering*/
int		rendering_image(t_monitor *monitor);
void	raycasting_image(t_monitor *monitor);
void	making_screen(t_monitor *monitor,
			int x, double per_wall_distance, int side);

/*initialize_map_texture.c*/

void	initalize_mapcolor(t_monitor *monitor, t_map *map);
void	initalize_setting_textures(t_monitor *monitor, char *elements[6]);

/* move_direction.c*/

void	turn_direction(t_monitor *monitor);
void	rotate_update(t_monitor *monitor, double radian);
void	rotate_vector(t_vec *vector, double degree);

#endif
