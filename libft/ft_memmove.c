/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:02:59 by eestell           #+#    #+#             */
/*   Updated: 2019/09/24 15:09:47 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			n;

	n = 0;
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (len == 0 || src == dst)
		return (dst);
	if (dst > src)
	{
		while (++n <= len)
			str1[len - n] = str2[len - n];
	}
	else
		while (len > 0)
		{
			*(str1++) = *(str2++);
			len--;
		}
	return (dst);
}
