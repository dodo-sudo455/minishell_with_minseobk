/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:21:49 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 15:43:19 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include <printf.h>

static const char	*_get_type_str(t_tokentype t)
{
	if (t == TOKEN_WORD)
		return ("TOKEN_WORD");
	if (t == TOKEN_PIPE)
		return ("TOKEN_PIPE");
	if (t == TOKEN_REDIR_IN)
		return ("TOKEN_REDIR_IN");
	if (t == TOKEN_REDIR_OUT)
		return ("TOKEN_REDIR_OUT");
	if (t == TOKEN_REDIR_HDOC)
		return ("TOKEN_REDIR_HDOC");
	if (t == TOKEN_REDIR_APPEND)
		return ("TOKEN_REDIR_APPEND");
	return ("TOKEN_UNKNOWN");
}

void	token_log(const t_token *tok_ref, size_t indent)
{
	log_indent(indent);
	printf("{\n");
	log_indent(indent + 1);
	printf("type: %s\n", _get_type_str(tok_ref->t));
	log_indent(indent + 1);
	printf("str: %s\n", tok_ref->s);
	log_indent(indent + 1);
	printf("quote: %d\n", tok_ref->has_quote);
	log_indent(indent);
	printf("}\n");
}
