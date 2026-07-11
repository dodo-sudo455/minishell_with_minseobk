/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:16:53 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/08 16:46:22 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	_token_del(void *ref)
{
	t_token	*tok_ref;

	tok_ref = ref;
	token_drop(tok_ref);
	free(tok_ref);
}

static t_error	_expand_node(t_ctx *c_ref, t_lst *node)
{
	t_token	*tok_ref;

	tok_ref = node->data;
	if (!token_is_word(tok_ref))
		return (ERROR_OK);
	if (ctx_expand(c_ref, &tok_ref->s) != ERROR_OK)
		return (geterr(c_ref));
	if (!tok_ref->s[0] && !tok_ref->has_quote)
		ft_lst_remove_with(node, _token_del);
	return (ERROR_OK);
}

t_error	parse_expand(t_ctx *c_ref, t_lst *toklst_ref)
{
	t_lst	*node;
	t_lst	*next;

	node = toklst_ref->next;
	while (node && node != toklst_ref)
	{
		next = node->next;
		if (_expand_node(c_ref, node) != ERROR_OK)
			return (geterr(c_ref));
		node = next;
	}
	return (ERROR_OK);
}
