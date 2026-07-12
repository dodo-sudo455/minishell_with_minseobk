/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toklst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:49:36 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 15:33:13 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

static void	_drop_token(void *ref)
{
	t_token	*tok_ref;

	tok_ref = ref;
	token_drop(tok_ref);
}

void	toklst_drop(t_lst *lst_ref)
{
	ft_lst_drop_with(lst_ref, _drop_token);
}

void	toklst_log(const t_lst *toklst_ref, size_t indent)
{
	const t_lst	*nod_ref;

	log_indent(indent);
	printf("[\n");
	nod_ref = toklst_ref->next;
	while (nod_ref && nod_ref != toklst_ref)
	{
		token_log(nod_ref->data, indent + 1);
		nod_ref = nod_ref->next;
	}
	log_indent(indent);
	printf("]\n");
}
