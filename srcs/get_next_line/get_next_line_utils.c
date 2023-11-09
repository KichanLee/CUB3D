/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:23:50 by kichan            #+#    #+#             */
/*   Updated: 2023/11/04 21:58:33 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch && ch[i])
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = "";
	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (dest == NULL)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr_two(char const *s, size_t start, size_t len)
{
	char	*string;
	size_t	size;
	size_t	i;

	i = 0;
	if (start > ft_strlen_gnl(s))
		size = 0;
	else if (len > ft_strlen_gnl(s + start))
		size = ft_strlen_gnl(s + start);
	else
		size = len;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string || !s)
		return (NULL);
	if (size)
		while (i < len && s[start])
			string[i++] = s[start++];
	string[i] = '\0';
	return (string);
}

int	ft_strchr_two(const char *s, int c)
{
	char	*cp;
	int		i;

	i = 0;
	cp = (char *) s;
	while (*cp)
	{
		if ((unsigned char)*cp == (unsigned char) c)
			return (i);
		++cp;
		++i;
	}
	if ((unsigned char)*cp == (unsigned char )c)
		return (i);
	return (-1);
}

int	ft_errorcheck(int fd, char **where)
{
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		free(*where);
		*where = NULL;
		return (-1);
	}
	return (0);
}
