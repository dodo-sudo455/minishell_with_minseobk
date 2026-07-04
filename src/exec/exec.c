/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:38:14 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/04 17:28:47 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_error	exec(t_ctx *c_ref, t_lst *toklst_ref)
{
	t_cmd	cmd;
	t_lst	cmdlst;
	t_token	*tok_ref;

	while (!ft_lst_is_empty(toklst_ref))
	{
		tok_ref = ft_lst_pop_front(toklst_ref);
		if (tok_ref->t == )
	}
}
