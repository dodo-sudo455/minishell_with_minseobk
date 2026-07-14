/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:01:42 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 20:26:34 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	cmdlst_log(const t_lst *cmdlst_ref, size_t indent)
{
	const t_lst	*nod_ref;

	log_indent(indent);
	printf("[\n");
	nod_ref = cmdlst_ref->next;
	while (nod_ref && nod_ref != cmdlst_ref)
	{
		cmd_log((t_cmd *)nod_ref->data, indent + 1);
		nod_ref = nod_ref->next;
	}
	log_indent(indent);
	printf("]\n");
}

static void	_cmd_drop(void *ref)
{
	cmd_drop((t_cmd *)ref);
}

void	cmdlst_clear(t_lst *cmdlst_ref)
{
	ft_lst_clear_with(cmdlst_ref, _cmd_drop);
}
