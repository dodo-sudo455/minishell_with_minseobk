/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:06:30 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 20:26:34 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	_redir_drop(void *ref)
{
	redir_drop((t_redir *)ref);
}

void	redlst_clear(t_lst *redlst_ref)
{
	ft_lst_clear_with(redlst_ref, _redir_drop);
}

void	redlst_log(const t_lst *redlst_ref, size_t indent)
{
	const t_lst		*nod_ref;
	const t_redir	*red_ref;
	bool			is_first;

	log_indent(indent);
	printf("[");
	nod_ref = redlst_ref->next;
	is_first = true;
	while (nod_ref && nod_ref != redlst_ref)
	{
		if (!is_first)
			printf(", ");
		red_ref = nod_ref->data;
		redir_log(red_ref);
		nod_ref = nod_ref->next;
		is_first = false;
	}
	printf("]\n");
}
