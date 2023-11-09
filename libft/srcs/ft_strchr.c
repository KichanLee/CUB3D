/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:23:18 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/16 17:56:25 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*cp;

	cp = (char *) s;
	while (*cp)
	{
		if ((unsigned char)*cp == (unsigned char) c)
			return (cp);
		++cp;
	}
	if ((unsigned char)*cp == (unsigned char )c)
		return (cp);
	return (0);
}
