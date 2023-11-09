/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:33 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 02:29:34 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map		*create_map(char *file);
static void	initialize(t_map **p_map, t_list **p_list);
static void	finalize(t_list **head);

t_map	*create_map(char *file)
{
	t_map	*map;
	t_list	*setting_map;
	t_list	*down_map;

	check_extension(file);
	initialize(&map, &setting_map);
	file_down(&setting_map, file);
	down_map = split_file(setting_map->next);
	parse_map(map, down_map);
	check_map(map);
	set_rgb(map);
	finalize(&setting_map);
	return (map);
}

static void	initialize(t_map **map, t_list **list)
{
	*map = ft_calloc(1, sizeof(t_map));
	if (!*map)
		exception_handler(err_general);
	*list = ft_calloc(1, sizeof(t_list));
	if (!*list)
		exception_handler(err_general);
}

static void	finalize(t_list **head)
{
	ft_lstclear(head, free);
}
