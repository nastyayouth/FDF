/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:50:59 by eestell           #+#    #+#             */
/*   Updated: 2019/09/25 10:36:07 by eestell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int n)
{
	size_t		count;

	count = 1;
	while (n / 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char		*ft_itoa_neg(int n)
{
	char		*number;
	size_t		count;
	int			number2;

	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	n = n * (-1);
	number2 = n;
	count = ft_count(n);
	count++;
	if (!(number = ft_strnew(count)))
		return (NULL);
	while (count--)
	{
		number2 = (n % 10);
		number[count] = number2 + '0';
		n = n / 10;
	}
	number[0] = '-';
	return (number);
}

char			*ft_itoa(int n)
{
	char		*number;
	size_t		count;
	int			number2;

	if (n < 0)
		return (ft_itoa_neg(n));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	number2 = n;
	count = ft_count(n);
	if (!(number = ft_strnew(count)))
		return (NULL);
	while (count--)
	{
		number2 = (n % 10);
		number[count] = number2 + '0';
		n = n / 10;
	}
	return (number);
}
