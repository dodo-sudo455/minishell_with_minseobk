/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:29:01 by minseobk          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

int	ft_lst_push(t_lst *l_ref, void *data)
{
	t_lstnode	*nod_ref;

	nod_ref = ft_lstnode_new(data);
	if (!nod_ref)
		return (1);
	if (!l_ref->head)
	{
		l_ref->head = nod_ref;
		l_ref->tail = nod_ref;
		l_ref->size += 1;
	}
	else
	{
		l_ref->tail->next = nod_ref;
		nod_ref->prev = l_ref->tail;
		l_ref->tail = nod_ref;
		l_ref->size += 1;
	}
	return (0);
}

int	ft_lst_push_front(t_lst *l_ref, void *data)
{
	t_lstnode	*nod_ref;

	nod_ref = ft_lstnode_new(data);
	if (!nod_ref)
		return (1);
	if (!l_ref->head)
	{
		l_ref->head = nod_ref;
		l_ref->tail = nod_ref;
		l_ref->size += 1;
	}
	else
	{
		nod_ref->next = l_ref->head;
		l_ref->head->prev = nod_ref;
		l_ref->head = nod_ref;
		l_ref->size += 1;
	}
	return (0);
}
