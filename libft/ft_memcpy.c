/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:56:06 by eestell           #+#    #+#             */
/*   Updated: 2019/09/24 15:06:50 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			len;

	if (n == 0 || dst == src)
		return (dst);
	len = 0;
	str2 = (unsigned char*)src;
	str1 = (unsigned char*)dst;
	while (len < n)
	{
		str1[len] = str2[len];
		len++;
	}
	return (str1);
}
