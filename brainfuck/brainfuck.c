/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:28:41 by lchappon          #+#    #+#             */
/*   Updated: 2018/03/06 10:42:28 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		ft_brainfuck(char *str)
{
	char	*ptr;
	int		i;
	int		count;

	count = 0;
	i = 0;
	ptr = (char *)malloc(sizeof(char) * 2048);
	while (str[i])
	{
		if (str[i] == '>')
			ptr++;
		else if (str[i] == '<')
			ptr--;
		else if (str[i] == '+')
			(*ptr)++;
		else if (str[i] == '-')
			(*ptr)--;
		else if (str[i] == '.')
			write(1, ptr, 1);
		else if (str[i] == '[' && *ptr == 0)
		{
			count = 0;
			while (1)
			{
				if (str[i] == '[')
					count++;
				if (str[i] == ']' && count > 0)
					count--;
				if (str[i] == ']' && count == 0)
					break ;
				i++;
			}
		}
		else if (str[i] == ']' && *ptr != 0)
		{
			count = 0;
			while (1)
			{
				if (str[i] == ']')
					count++;
				if (str[i] == '[' && count > 0)
					count--;
				if (str[i] == '[' && count == 0)
					break ;
				i--;
			}
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		ft_brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
