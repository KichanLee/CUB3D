/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:52:22 by kichlee           #+#    #+#             */
/*   Updated: 2023/11/05 02:36:20 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = 0;
	while (s1[len])
		++len;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	*str = '\0';
	while (len--)
		--str;
	return (str);
}
