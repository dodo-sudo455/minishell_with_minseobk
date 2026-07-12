/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:17:09 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/12 13:40:21 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	_is_quote(int *state, char c)
{
	if (c == '\'' && *state != 2)
	{
		if (*state == 1)
			*state = 0;
		else
			*state = 1;
		return (true);
	}
	if (c == '"' && *state != 1)
	{
		if (*state == 2)
			*state = 0;
		else
			*state = 2;
		return (true);
	}
	return (false);
}

static t_error	_strip_quote_str(t_ctx *c_ref, const char *src, char **dst)
{
	t_vec	vec;
	size_t	i;
	int		state;

	vec = ft_vec_make(ft_strlen(src));
	i = 0;
	state = 0;
	while (src[i])
	{
		if (_is_quote(&state, src[i]))
		{
			i += 1;
			continue ;
		}
		if (ft_vec_push(&vec, src[i]) != 0)
			return (ft_vec_drop(&vec), seterr(c_ref, ERROR_INTERNAL));
		i += 1;
	}
	if (state != 0)
		return (ft_vec_drop(&vec), seterr(c_ref, ERROR_SYN));
	*dst = ft_vec_to_str(&vec);
	ft_vec_drop(&vec);
	if (!*dst)
		return (seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}

static t_error	_quote_node(t_ctx *c_ref, t_token *tok_ref)
{
	char	*tmp;

	if (!token_is_word(tok_ref))
		return (ERROR_OK);
	if (_strip_quote_str(c_ref, tok_ref->s, &tmp) != ERROR_OK)
		return (geterr(c_ref));
	free(tok_ref->s);
	tok_ref->s = tmp;
	return (ERROR_OK);
}

t_error	parse_quote(t_ctx *c_ref, t_lst *toklst_ref)
{
	t_lst	*node;

	node = toklst_ref->next;
	while (node && node != toklst_ref)
	{
		if (_quote_node(c_ref, node->data) != ERROR_OK)
			return (geterr(c_ref));
		node = node->next;
	}
	return (ERROR_OK);
}
