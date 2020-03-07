/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <eestell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:51:15 by dshala            #+#    #+#             */
/*   Updated: 2020/03/07 19:38:35 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strsplit_count_word(char *s, char c)
{
	size_t	count;

	count = 0;
	while (s && *s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t		ft_strsplit_count_len(char *s, char c)
{
	size_t	countc;

	countc = 0;
	while (*s && *s != c)
	{
		countc++;
		s++;
	}
	return (countc);
}

static char			**ft_free(char **str, size_t i)
{
	while (i > 0)
	{
		free(str[i]);
		i--;
	}
	free(str[i]);
	free(str);
	str = NULL;
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	countc;
	size_t	count;
	size_t	a;
	
	a = 0;
	if (!s)
		return (NULL);
	count = ft_strsplit_count_word((char*)s, c);
	if (!(new = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	while (a < count)
	{
		countc = 0;
		while (s && *s && *s == c)
			s++;
		countc = ft_strsplit_count_len((char*)s, c);
		if (!(new[a] = ft_strsub(s, 0, countc)))
			return (ft_free(new, a));
		while (s && *s && *s != c)
			s++;
		a++;
	}
	new[a] = NULL;
	return (new);
}
