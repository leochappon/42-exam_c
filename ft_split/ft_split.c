/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:15:57 by lchappon          #+#    #+#             */
/*   Updated: 2018/03/03 14:27:03 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int			count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && space(str[i]))
			i++;
		if (str[i] && !space(str[i]))
		{
			count++;
			while (str[i] && !space(str[i]))
				i++;
		}
	}
	return (count);
}

char		*malloc_word(char *str, int i)
{
	char	*ptr;
	int		j;

	j = 0;
	while (str[i + j] && !space(str[i + j]))
		j++;
	ptr = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[i + j] && !space(str[i + j]))
	{
		ptr[j] = str[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char		**ft_split(char *str)
{
	char	**tab;
	int		count;
	int		i;
	int		x;

	x = 0;
	i = 0;
	count = count_words(str);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	while (str[i])
	{
		while (str[i] && space(str[i]))
			i++;
		if (str[i] && !space(str[i]))
		{
			tab[x] = malloc_word(str, i);
			x++;
			while (str[i] && !space(str[i]))
				i++;
		}
	}
	tab[x] = NULL;
	return (tab);
}
