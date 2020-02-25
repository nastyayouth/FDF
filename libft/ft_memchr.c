/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:42:38 by eestell           #+#    #+#             */
/*   Updated: 2019/09/25 10:56:04 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			len;

	s1 = (unsigned char*)s;
	len = 0;
	while (len < n)
	{
		if (s1[len] == (unsigned char)c)
			return (&s1[len]);
		len++;
	}
	return (NULL);
}
