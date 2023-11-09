/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:38:54 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/16 19:28:03 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t_len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(t_len + 1);
	if (!str)
		return (0);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		++i;
	}
	while (i < t_len)
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}
