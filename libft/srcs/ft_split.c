/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:21:00 by kichlee           #+#    #+#             */
/*   Updated: 2022/12/14 13:17:46 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**free_all(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free (str);
	str = 0;
	return (0);
}

int	count_str(char const *str, char ch)
{
	int	flag;
	int	cnt;

	flag = 1;
	cnt = 0;
	while (*str)
	{
		if (flag == 1 && (*str) != ch)
		{
			flag = 0;
			cnt ++;
		}
		if (flag == 0 && (*str) == ch)
			flag = 1;
		str++;
	}
	return (cnt);
}

int	str_len_ex_sep(char const *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	return (i);
}

char	*put_word(char const *str, char ch)
{	
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = str_len_ex_sep(str, ch);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**string;
	int		i;

	cnt = count_str(s, c);
	i = 0;
	string = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!string)
		return (0);
	while (*s != '\0')
	{
		while (*s && ((*s) == c))
			s++;
		if (*s)
		{
			string[i] = put_word(s, c);
			if (!string[i])
				return (free_all(string, i));
			i++;
		}
		while (*s && ((*s) != c))
			s++;
	}
	string[i] = 0;
	return (string);
}
