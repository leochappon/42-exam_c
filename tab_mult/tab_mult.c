/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:14:39 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/22 17:05:18 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int			ft_atoi(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == '\r'
				|| s[i] == '\v' || s[i] == '\f' || s[i] == ' '
				|| s[i] == '-' || s[i] == '+'))
			i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		res = res + s[i] - 48;
		if (s[i + 1] && (s[i + 1] >= '0' && s[i + 1] <= '9'))
			res = res * 10;
		i++;
	}
	return (res);
}

void		ft_tab_mult(char *s)
{
	int		i;
	int		x;

	i = 1;
	x = ft_atoi(s);
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putstr(s);
		ft_putstr(" = ");
		ft_putnbr(i * x);
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_tab_mult(argv[1]);
	}
	else
		ft_putchar('\n');
	return (0);
}
