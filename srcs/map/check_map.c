/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:45 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 16:44:15 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_map(t_map *map);
t_bool			check_empty_line(char *line);
static void		check_map_elements(char *elements[]);
static void		check_map_contents(t_map *map);
static t_bool	check_content(char content, t_map *map, int x, int y);

void	check_map(t_map *map)
{
	check_map_elements(map->elements);
	check_map_contents(map);
	check_closed_wall(map);
	if (map->start_x == -1 || map->start_y == -1)
		exception_handler(err_player);
}

t_bool	check_empty_line(char *line)
{
	char	*trimed_line;
	t_bool	value;

	value = FALSE;
	trimed_line = ft_strtrim(line, " ");
	if (!trimed_line)
		exception_handler(err_general);
	if (*trimed_line == '\n')
		value = TRUE;
	free(trimed_line);
	return (value);
}

static void	check_map_elements(char *elements[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!elements[i])
			exception_handler(err_id);
		i++;
	}
}

static void	check_map_contents(t_map *map)
{
	int		h;
	int		w;
	char	**contents;

	h = 0;
	contents = map->contents;
	if (!contents || !*contents)
		exception_handler(err_map);
	while (contents[h])
	{
		if (!contents[h] || !*contents[h] \
		|| check_empty_line(contents[h]) == TRUE)
			exception_handler(err_map);
		w = 0;
		while (contents[h][w])
		{
			if (check_content(contents[h][w], map, w, h) == FALSE)
				exception_handler(err_map);
			w++;
		}
		if (w > map->width)
			map->width = w;
		h++;
	}
	map->height = h;
}

static t_bool	check_content(char content, t_map *map, int x, int y)
{
	if (content == '1'
		|| content == '0'
		|| content == ' ')
		return (TRUE);
	else if (
		(content == 'E' || content == 'W' || content == 'S' || content == 'N')
		&& (map->start_x == -1 && map->start_y == -1)
	)
	{
		map->start_x = x;
		map->start_y = y;
		map->start_dir = content;
		map->contents[y][x] = '0';
		return (TRUE);
	}
	else
		return (FALSE);
}
