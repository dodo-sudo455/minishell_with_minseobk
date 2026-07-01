/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:34:15 by minseobk          #+#    #+#             */
/*   Updated: 2026/06/16 16:46:59 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_lstiter	ft_lstiter_make(const t_lst *l_ref)
{
	t_lstiter	iter;

	iter.nod_ref = l_ref->head;
	iter.i = 0;
	iter.n_ref = &l_ref->size;
	return (iter);
}

bool	ft_lstiter_has_next(const t_lstiter *i_ref)
{
	return (i_ref->i < *i_ref->n_ref);
}

bool	ft_lstiter_has_prev(const t_lstiter *i_ref)
{
	return (0 < i_ref->i);
}

void	*ft_lstiter_next(t_lstiter *i_ref)
{
	void	*data;

	if (i_ref->i >= *i_ref->n_ref)
		return (NULL);
	data = i_ref->nod_ref->data;
	i_ref->nod_ref = i_ref->nod_ref->next;
	i_ref->i += 1;
	return (data);
}

void	*ft_lstiter_prev(t_lstiter *i_ref)
{
	void	*data;

	if (i_ref->i == 0)
		return (NULL);
	data = i_ref->nod_ref->data;
	i_ref->nod_ref = i_ref->nod_ref->prev;
	i_ref->i -= 1;
	return (data);
}
