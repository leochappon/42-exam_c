/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:42:11 by lchappon          #+#    #+#             */
/*   Updated: 2018/02/12 14:10:21 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void		ft_fprime(int n)
{
	int		m;

	m = 2;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	while (n > 1)
	{
		if (n % m == 0)
		{
			printf("%d", m);
			n = n / m;
			if (n > 1)
				printf("*");
			m = 2;
		}
		else
			m++;
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_fprime(atoi(argv[1]));
	}
	printf("\n");
	return (0);
}
