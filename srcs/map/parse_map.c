/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:27 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 02:38:31 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			parse_map(t_map *map, t_list *lst_map);
static void		parse_map_elements(char **elements, t_list **lst_map);
static char		**parse_element(char *str);
static t_id		get_element_id(char *id_str);
static void		parse_map_contents(char ***contents, t_list *lst_map);

void	parse_map(t_map *map, t_list *lst_map)
{
	t_list	*temp;

	temp = lst_map;
	parse_map_elements(map->elements, &temp);
	parse_map_contents(&map->contents, temp);
	map->start_x = -1;
	map->start_y = -1;
}

static void	parse_map_elements(char **elements, t_list **lst_map)
{
	t_list		*temp;
	char		**ele;
	int			idx;
	t_id		base_id;

	idx = 0;
	temp = *lst_map;
	while (idx < 6 && temp)
	{
		ele = parse_element(temp->content);
		if (ele)
		{
			base_id = get_element_id(ele[0]);
			if (base_id != invalid)
			{
				elements[base_id] = ft_substr(ele[1], 0, ft_strlen(ele[1]) - 1);
				if (!elements[base_id])
					exception_handler(err_general);
			}
			free_arr(ele);
		}
		idx++;
		temp = temp->next;
	}
	*lst_map = temp;
}

static char	**parse_element(char *str)
{
	char	**element;
	int		idx;

	idx = 0;
	element = ft_split(str, ' ');
	if (!element)
		exception_handler(err_general);
	while (element[idx])
		idx++;
	if (idx != 2)
	{
		free_arr(element);
		return (0);
	}
	else
		return (element);
}

static t_id	get_element_id(char *id_str)
{
	if (!ft_strncmp("WE\0", id_str, 3))
		return (we);
	else if (!ft_strncmp("SO\0", id_str, 3))
		return (so);
	else if (!ft_strncmp("NO\0", id_str, 3))
		return (no);
	else if (!ft_strncmp("EA\0", id_str, 3))
		return (ea);
	else if (!ft_strncmp("F\0", id_str, 2))
		return (id_f);
	else if (!ft_strncmp("C\0", id_str, 2))
		return (id_c);
	else
		return (invalid);
}

static void	parse_map_contents(char ***p_contents, t_list *lst_map)
{
	int		i;
	int		size;
	char	**contents;
	t_list	*temp;

	temp = lst_map;
	size = ft_lstsize(lst_map);
	contents = ft_calloc((size + 1), sizeof(char *));
	if (!contents)
		exception_handler(err_general);
	contents[size] = 0;
	i = 0;
	while (temp)
	{
		contents[i] = ft_substr(temp->content, 0, \
		ft_strlen(temp->content) - 1);
		if (!contents[i])
			exception_handler(err_general);
		i++;
		temp = temp->next;
	}
	*p_contents = contents;
}
