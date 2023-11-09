/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:49:44 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/16 17:51:00 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (i < s)
	{
		if (((unsigned char *)ptr1)[i] != ((unsigned char *)ptr2)[i])
		{
			return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
		}
		++i;
	}
	return (0);
}
