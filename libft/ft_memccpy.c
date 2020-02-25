/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:22:51 by eestell           #+#    #+#             */
/*   Updated: 2019/09/21 18:00:56 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			len;
	unsigned		ch;

	len = 0;
	ch = (unsigned char)c;
	str1 = (unsigned char*)src;
	str2 = (unsigned char*)dst;
	while (len < n)
	{
		str2[len] = str1[len];
		if (str1[len] == ch)
			return (&str2[len + 1]);
		len++;
	}
	return (NULL);
}
