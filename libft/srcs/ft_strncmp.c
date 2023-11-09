/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:33:24 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/16 18:18:54 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t t)
{
	size_t	s;

	s = 0;
	while ((unsigned char)(*s1) && s < t)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		++s1;
		++s2;
		++s;
	}
	if ((unsigned char)*s1 == '\0' && s < t)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
