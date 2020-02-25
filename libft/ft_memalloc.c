/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmaloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:03:18 by eestell           #+#    #+#             */
/*   Updated: 2019/09/24 15:05:52 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	if ((str = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return (str);
}
