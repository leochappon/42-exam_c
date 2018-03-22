/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:47:01 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/22 15:48:11 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_rstr_cap(char *s)
{
	int		i;
	int		word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (word == 0 && (s[i] != '\t' && s[i] != ' '))
			word = 1;
		if (word == 1 && (s[i] >= 'A' && s[i] <= 'Z'))
			s[i] = s[i] - 'A' + 'a';
		if ((s[i] >= 'a' && s[i] <= 'z')
				&& (s[i + 1] == '\t' || s[i + 1] == ' ' || !s[i + 1]))
		{
			s[i] = s[i] - 'a' + 'A';
			word = 0;
		}
		ft_putchar(s[i]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (argc > 1 && i < argc)
	{
		ft_rstr_cap(argv[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
