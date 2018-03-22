/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:19:22 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/27 14:27:50 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_rrange(int start, int end)
{
	int		*tab;
	int		i;
	int		size;

	i = 0;
	size = 1;
	if (start > end)
		size = start - end + 1;
	else if (start < end)
		size = end - start + 1;
	tab = (int *)malloc(sizeof(int) * size + 1);
	while (size)
	{
		if (start >= end)
		{
			tab[i] = end;
			end++;
		}
		else if (start <= end)
		{
			tab[i] = end;
			end--;
		}
		i++;
		size--;
	}
	tab[i] = '\0';
	return (tab);
}
