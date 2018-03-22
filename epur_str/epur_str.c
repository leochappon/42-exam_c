/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:08:24 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/29 16:26:22 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_epur_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		while (str[i] && (str[i] != '\t' && str[i] != ' '))
		{
			ft_putchar(str[i]);
			i++;
		}
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
		{
			if (str[i + 1] && (str[i + 1] != '\t' && str[i + 1] != ' '))
				ft_putchar(' ');
			i++;
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_epur_str(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
