/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:40:28 by lchappon          #+#    #+#             */
/*   Updated: 2018/03/03 16:53:46 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

int			ft_nbrlen(int nbr)
{
	int		length;

	length = (nbr <= 0) ? 1 : 0;
	while (nbr)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		length;
	int		is_neg;

	is_neg = (nbr < 0) ? 1 : 0;
	length = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	length--;
	while (length >= 0)
	{
		str[length] = ft_abs(nbr % 10) + 48;
		nbr = ft_abs(nbr / 10);
		length--;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
