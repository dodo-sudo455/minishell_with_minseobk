/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:29:01 by minseobk          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdlib.h>

t_lstnode	*ft_lstnode_new(void *data)
{
	t_lstnode	*nod_ref;

	nod_ref = malloc(sizeof(t_lstnode));
	if (!nod_ref)
		return (NULL);
	nod_ref->data = data;
	nod_ref->next = NULL;
	nod_ref->prev = NULL;
	return (nod_ref);
}

void	*ft_lstnode_cons(t_lstnode *nod_ref)
{
	void	*data;

	data = nod_ref->data;
	free(nod_ref);
	return (data);
}
