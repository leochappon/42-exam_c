/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:23:34 by lchappon          #+#    #+#             */
/*   Updated: 2018/01/26 15:06:50 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list			*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int			tmp;
	t_list		*begin;

	begin = lst;
	while (lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = begin;
		}
		else
			lst = lst->next;
	}
	lst = begin;
	return (lst);
}
