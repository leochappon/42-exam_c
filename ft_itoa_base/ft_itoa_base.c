/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:03:41 by lchappon          #+#    #+#             */
/*   Updated: 2018/03/21 14:03:22 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_valuelen(int value, int base)
{
	int		length;

	length = ((value < 0 && base == 10) || value == 0) ? 1 : 0;
	while (value)
	{
		value /= base;
		length++;
	}
	return (length);
}

int			ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		length;
	int		is_neg;

	is_neg = value < 0 && base == 10 ? 1 : 0;
	length = ft_valuelen(value, base);
	str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	length--;
	while (length >= 0)
	{
		str[length] = ft_abs(value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = ft_abs(value / base);
		length--;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
