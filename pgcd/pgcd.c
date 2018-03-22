/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:58:45 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/22 14:38:21 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			ft_pgcd(int a, int b)
{
	int		k;

	k = 0;
	if (a >= b)
		k = a;
	else if (b > a)
		k = b;
	while (k > 1)
	{
		if (a % k == 0 && b % k == 0)
			return (k);
		k--;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%i", ft_pgcd(atoi(argv[1]), atoi(argv[2])));
	}
	printf("\n");
	return (0);
}
