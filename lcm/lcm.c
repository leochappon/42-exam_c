/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:39:31 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/13 17:24:03 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		lcm(unsigned int a, unsigned int b)
{
	unsigned int	am;
	unsigned int	bm;
	unsigned int	ar;
	unsigned int	br;

	am = 1;
	bm = 1;
	ar = a;
	br = b;
	if (!a || !b)
		return (0);
	while (ar != br)
	{
		if (ar < br)
		{
			ar = a * am;
			am++;
		}
		else if (br < ar)
		{
			br = b * bm;
			bm++;
		}
	}
	return (ar);
}
