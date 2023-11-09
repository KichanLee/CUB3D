/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:38 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 16:44:15 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_closed_wall(t_map *map);
static t_bool	check_closed_wall_internal(char **contents,
					int *lens_4_compare, int w, int h);
static t_bool	check_based_space(char **contents, int w, int h);
static t_bool	check_based_blank(char **contents,
					int w, int h, int compare_len);

void	check_closed_wall(t_map *map)
{
	int	h;
	int	w;
	int	len_set_com[3];

	h = 0;
	len_set_com[1] = ft_strlen(map->contents[0]);
	while (map->contents[h])
	{
		if (h < map->height - 1)
			len_set_com[2] = ft_strlen(map->contents[h + 1]);
		w = 0;
		while (map->contents[h][w])
		{
			if (check_closed_wall_internal(map->contents,
					len_set_com, w, h) == FALSE)
				exception_handler(err_wall);
			w++;
		}
		len_set_com[0] = len_set_com[1];
		len_set_com[1] = len_set_com[2];
		h++;
	}
}

static t_bool	check_closed_wall_internal(char **contents,
					int *len_set_com, int w, int h)
{
	int	ignore_len;

	ignore_len = 2147483647;
	if (contents[h][w] == '0')
	{
		if (check_based_space(contents, w + 1, h)
			&& check_based_space(contents, w - 1, h)
			&& check_based_space(contents, w, h + 1)
			&& check_based_space(contents, w, h - 1))
			return (TRUE);
		else
			return (FALSE);
	}
	else if (contents[h][w] == ' ')
	{
		if (check_based_blank(contents, w + 1, h, ignore_len)
			&& check_based_blank(contents, w - 1, h, ignore_len)
			&& check_based_blank(contents, w, h + 1, len_set_com[2])
			&& check_based_blank(contents, w, h - 1, len_set_com[0]))
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (TRUE);
}

static t_bool	check_based_space(char **contents, int w, int h)
{
	if (w == -1 || h == -1)
		return (FALSE);
	else if (contents[h] == 0 || contents[h][w] == 0 || contents[h][w] == ' ')
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_based_blank(char **contents,
					int w, int h, int compare_len)
{
	if (w == -1 || h == -1 || w > compare_len)
		return (TRUE);
	else if (contents[h] == 0 || contents[h][w] == 0)
		return (TRUE);
	else if (contents[h][w] == '0')
		return (FALSE);
	else
		return (TRUE);
}
