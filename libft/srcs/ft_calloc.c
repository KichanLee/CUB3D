/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:56:08 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/14 13:00:15 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t c, size_t s)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(c * s);
	if (!ptr)
		return (0);
	while (i < (c * s))
	{
		((unsigned char *)ptr)[i] = 0;
		++i;
	}
	return (ptr);
}
