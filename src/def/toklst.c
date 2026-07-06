/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toklst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:49:36 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 13:52:08 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

static void	_drop_token(void *ref)
{
	t_token	*tok_ref;

	tok_ref = ref;
	token_drop(tok_ref);
	free(tok_ref);
}

void	toklst_drop(t_lst *lst_ref)
{
	ft_lst_drop_with(lst_ref, _drop_token);
}
