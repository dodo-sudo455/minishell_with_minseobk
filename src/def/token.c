/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:31:25 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 17:04:59 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"
#include "libft.h"

static inline t_tokentype	_map_type(const char *s)
{
	if (ft_strcmp(s, "|") == 0)
		return (TOKEN_PIPE);
	if (ft_strcmp(s, "<") == 0)
		return (TOKEN_REDIR_IN);
	if (ft_strcmp(s, ">") == 0)
		return (TOKEN_REDIR_OUT);
	if (ft_strcmp(s, "<<") == 0)
		return (TOKEN_REDIR_HDOC);
	if (ft_strcmp(s, ">>") == 0)
		return (TOKEN_REDIR_APPEND);
	return (TOKEN_WORD);
}

static inline bool	_has_quote(const char *s)
{
	while (*s)
	{
		if (*s == '\'' || *s == '"')
			return (true);
		s += 1;
	}
	return (false);
}

t_token	*token_new(char *s)
{
	t_token	*tok_ref;

	tok_ref = malloc(sizeof(t_token));
	if (!tok_ref)
		return (NULL);
	tok_ref->t = _map_type(s);
	tok_ref->s = s;
	tok_ref->has_quote = _has_quote(s);
	return (tok_ref);
}

void	token_clear(t_token *tok_ref)
{
	if (!tok_ref)
		return ;
	if (tok_ref->s)
	{
		free(tok_ref->s);
		tok_ref->s = NULL;
	}
	tok_ref->t = 0;
	tok_ref->has_quote = false;
}

void	token_drop(t_token *tok_ref)
{
	if (!tok_ref)
		return ;
	token_clear(tok_ref);
	free(tok_ref);
}
