/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:49:19 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 13:49:29 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

bool	token_is_redir(const t_token *tok_ref)
{
	return (tok_ref->t == TOKEN_REDIR_IN
		|| tok_ref->t == TOKEN_REDIR_OUT
		|| tok_ref->t == TOKEN_REDIR_HDOC
		|| tok_ref->t == TOKEN_REDIR_APPEND);
}

bool	token_is_meta(const t_token *tok_ref)
{
	return (tok_ref->t != TOKEN_WORD);
}
