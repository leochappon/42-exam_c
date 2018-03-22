/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:01:05 by lchappon          #+#    #+#             */
/*   Updated: 2018/03/03 17:18:04 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write (1, &c, 1);
}

int			space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

void		ft_rev_wstr(char *s)
{
	int		a;
	int		z;

	z = 0;
	while (s[z])
		z++;
	z--;
	while (s[z])
	{
		a = 0;
		while (s[z] && !space(s[z]))
			z--;
		while (s[z + 1 + a] && !space(s[z + 1 + a]))
		{
			ft_putchar(s[z + 1 + a]);
			a++;
		}
		if (space(s[z]))
		{
			ft_putchar(s[z]);
			z--;
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_rev_wstr(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
