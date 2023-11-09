/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:29:09 by donghong          #+#    #+#             */
/*   Updated: 2023/11/05 16:44:15 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list			*split_file(t_list *lst_map);
static void		lst_remove(t_list **pre, t_list **curr);
void			file_down(t_list **head, char *file);
void			check_extension(char *file);

void	check_extension(char *file)
{
	char	*valid;

	if (file)
	{
		valid = ft_strrchr(file, '.');
		if (!valid
			|| ft_strncmp(valid, ".cub\0", ft_strlen(".cub\0") + 1))
			exception_handler(err_file);
		else
			return ;
	}
	else
		exception_handler(err_arg);
}

void	file_down(t_list **head, char *file)
{
	char	*line;
	int		fd;
	t_list	*new_node;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exception_handler(err_file);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			new_node = ft_lstnew(line);
			if (!new_node)
				exception_handler(err_general);
			ft_lstadd_back(head, new_node);
		}
		else
			return ;
	}
}

t_list	*split_file(t_list *lst_map)
{
	t_list	*temp;
	t_list	*pre;
	int		empty;

	empty = 0;
	while (lst_map && check_empty_line(lst_map->content) == TRUE)
		lst_map = lst_map->next;
	temp = lst_map;
	while (temp && empty <= 6)
	{
		if (check_empty_line(temp->content) == TRUE)
			lst_remove(&pre, &temp);
		else
			empty++;
		pre = temp;
		temp = temp->next;
	}
	return (lst_map);
}

static void	lst_remove(t_list **pre, t_list **curr)
{
	t_list	*del;

	(*pre)->next = (*curr)->next;
	del = *curr;
	*curr = *pre;
	ft_lstdelone(del, free);
}
