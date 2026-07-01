/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:29:01 by minseobk          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

void	*ft_lst_pop(t_lst *l_ref)
{
	t_lstnode	*nod_ref;

	if (ft_lst_is_empty(l_ref))
		return (NULL);
	nod_ref = l_ref->tail;
	if (l_ref->size == 1)
	{
		l_ref->head = NULL;
		l_ref->tail = NULL;
	}
	else
	{
		nod_ref->prev->next = NULL;
		l_ref->tail = nod_ref->prev;
	}
	l_ref->size -= 1;
	return (ft_lstnode_cons(nod_ref));
}

void	*ft_lst_pop_front(t_lst *l_ref)
{
	t_lstnode	*nod_ref;

	if (ft_lst_is_empty(l_ref))
		return (NULL);
	nod_ref = l_ref->head;
	if (l_ref->size == 1)
	{
		l_ref->head = NULL;
		l_ref->tail = NULL;
	}
	else
	{
		nod_ref->next->prev = NULL;
		l_ref->head = nod_ref->next;
	}
	l_ref->size -= 1;
	return (ft_lstnode_cons(nod_ref));
}
