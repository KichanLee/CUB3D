/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:16 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 02:29:18 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						set_rgb(t_map *map);
static unsigned long long	parse_rgb(char *rgb);
static int					check_rgb(char *rgb);
static int					check_range(int value);

void	set_rgb(t_map *map)
{
	if (map->elements[id_f])
		map->f_rgb = parse_rgb(map->elements[id_f]);
	if (map->elements[id_c])
		map->c_rgb = parse_rgb(map->elements[id_c]);
}

static unsigned long long	parse_rgb(char *rgb)
{
	int						i;
	char					**floor;
	unsigned long long		numeric_rgb[3];
	unsigned long long		hex_rgb;

	floor = ft_split(rgb, ',');
	if (!floor)
		exception_handler(err_general);
	i = 0;
	while (floor[i])
		i++;
	if (i != 3)
		exception_handler(err_rgb);
	i = 0;
	while (i < 3)
	{
		numeric_rgb[i] = check_rgb(floor[i]);
		i++;
	}
	hex_rgb = ((numeric_rgb[0] & 0xff) << 16) + ((numeric_rgb[1] & 0xff) << 8)
		+ ((numeric_rgb[2] & 0xff));
	free_arr(floor);
	return (hex_rgb);
}

static int	check_rgb(char *rgb)
{
	int	i;

	if (ft_strlen(rgb) > 3)
		exception_handler(err_rgb);
	else
	{
		i = 0;
		while (rgb[i])
		{
			if (!ft_isdigit(rgb[i]))
				exception_handler(err_rgb);
			i++;
		}
	}
	return (check_range(ft_atoi(rgb)));
}

static int	check_range(int value)
{
	if (value < 0 || value > 255)
	{
		exception_handler(err_rgb);
		return (-1);
	}
	else
		return (value);
}
