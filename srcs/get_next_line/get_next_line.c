/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:49:42 by kichan            #+#    #+#             */
/*   Updated: 2023/11/04 21:58:02 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_initwhere(char **where)
{
	*where = malloc(BUFFER_SIZE + 1);
	if (*where == NULL)
		return (NULL);
	*where[0] = '\0';
	return (*where);
}

char	*handle_count_zero(char **where)
{
	char	*line;

	line = ft_substr_two(*where, 0, ft_strlen_gnl(*where));
	free(*where);
	*where = NULL;
	if (ft_strlen_gnl(line) <= 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*handle_newline(char **where, char **temp)
{
	char		*line;

	*temp = *where;
	line = ft_substr_two(*where, 0, ft_strchr_two(*where, '\n') + 1);
	if (!(line))
	{
		free(*temp);
		*where = NULL;
		return (NULL);
	}
	*where = ft_substr_two(*where, ft_strchr_two(*where, '\n') + 1, \
	ft_strlen_gnl(*where) - 1);
	free(*temp);
	if (*where == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*where_free(int cnt, char **where)
{
	if (cnt == -1)
	{
		free(*where);
		*where = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*where;
	char		*temp;
	int			count;

	if (ft_errorcheck(fd, &where) == -1 || \
	(where == NULL && !ft_initwhere(&where)))
		return (NULL);
	count = read(fd, buffer, BUFFER_SIZE);
	where_free(count, &where);
	while (count > 0 || ft_strchr_two(where, '\n') != -1)
	{
		buffer[count] = '\0';
		temp = where;
		where = ft_strjoin(where, buffer);
		free(temp);
		if (!where)
			return (NULL);
		if (ft_strchr_two(where, '\n') != -1)
			return (handle_newline(&where, &temp));
		count = read(fd, buffer, BUFFER_SIZE);
		where_free(count, &where);
	}
	return (handle_count_zero(&where));
}
