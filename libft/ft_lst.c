/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:29:01 by minseobk          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

t_lst	ft_lst_make(void)
{
	t_lst	l;

	l.size = 0;
	l.head = NULL;
	l.tail = NULL;
	return (l);
}

void	ft_lst_drop(t_lst *l_ref)
{
	t_lstnode	*p;
	t_lstnode	*q;

	if (!l_ref)
		return ;
	p = l_ref->head;
	while (p)
	{
		q = p->next;
		if (p->data)
			free(p->data);
		free(p);
		p = q;
	}
	ft_memset(l_ref, 0, sizeof(t_lst));
}

void	ft_lst_drop_with(t_lst *l_ref, void (*del)(void *))
{
	t_lstnode	*p;
	t_lstnode	*q;

	if (!l_ref)
		return ;
	p = l_ref->head;
	while (p)
	{
		q = p->next;
		del(p->data);
		free(p);
		p = q;
	}
	ft_memset(l_ref, 0, sizeof(t_lst));
}

bool	ft_lst_is_empty(const t_lst *l_ref)
{
	return (l_ref->size == 0);
}
