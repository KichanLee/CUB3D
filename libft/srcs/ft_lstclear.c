/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:33:55 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/16 20:43:11 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		first = (*lst)-> next;
		del((*lst)->content);
		free(*lst);
		*lst = first;
	}
	(*lst) = NULL;
}
