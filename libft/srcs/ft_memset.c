/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:41:12 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/14 17:08:11 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int n, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((unsigned char *)b)[i] = (unsigned char) n;
		i++;
	}
	return (b);
}
