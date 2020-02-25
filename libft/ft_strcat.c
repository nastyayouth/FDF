/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:52:06 by eestell           #+#    #+#             */
/*   Updated: 2019/09/24 15:11:07 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s3;

	s3 = s1 + ft_strlen(s1);
	while (*s2 != '\0')
		*s3++ = *s2++;
	*s3 = '\0';
	return (s1);
}
