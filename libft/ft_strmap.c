/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:36:00 by eestell           #+#    #+#             */
/*   Updated: 2019/09/21 23:44:55 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char		*fstr;
	size_t		i;
	size_t		j;

	i = 0;
	if (s && f)
	{
		j = ft_strlen((char *)s);
		fstr = (char *)malloc((j + 1) * sizeof(char));
		if (!fstr)
			return (NULL);
		while (s[i] != 0)
		{
			fstr[i] = f(s[i]);
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
