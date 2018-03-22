/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:20:59 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/15 17:32:40 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_range(int start, int end)
{
	int		*tab;
	int		i;
	int		size;

	i = 0;
	size = 1;
	if (start < end)
		size = end - start + 1;
	else if (start > end)
		size = start - end + 1;
	tab = (int *)malloc(sizeof(*tab) * (size) + 1);
	while (size)
	{
		if (start <= end)
		{
			tab[i] = start;
			start++;
		}
		else if (start >= end)
		{
			tab[i] = start;
			start--;
		}
		i++;
		size--;
	}
	tab[i] = '\0';
	return (tab);
}
