/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:41:43 by lchappon          #+#    #+#             */
/*   Updated: 2018/02/14 13:21:23 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_rostring(char *s)
{
	int		i;

	i = 0;
	while (s[i] && space(s[i]))
		i++;
	while (s[i] && !space(s[i]))
		i++;
	while (s[i] && space(s[i]))
		i++;
	while (s[i])
	{
		while (s[i] && !space(s[i]))
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_putchar(' ');
		while (s[i] && space(s[i]))
			i++;
	}
	i = 0;
	while (s[i] && space(s[i]))
		i++;
	while (s[i] && !space(s[i]))
	{
		ft_putchar(s[i]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_rostring(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
