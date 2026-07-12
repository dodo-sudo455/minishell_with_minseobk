/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:51:52 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/12 19:16:00 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_redir	*redir_new(t_redirtype type, const char *s)
{
	t_redir	*redir_ref;

	redir_ref = malloc(sizeof(t_redir));
	if (!redir_ref)
		return (NULL);
	redir_ref->t = type;
	redir_ref->s = ft_strdup(s);
	if (!redir_ref->s)
	{
		free(redir_ref);
		return (NULL);
	}
	return (redir_ref);
}

void	redir_drop(t_redir *redir_ref)
{
	if (!redir_ref)
		return ;
	free(redir_ref->s);
	free(redir_ref);
}

static void	_redir_drop(void *ref)
{
	redir_drop((t_redir *)ref);
}

void	redlst_clear(t_lst *redlst_ref)
{
	ft_lst_clear_with(redlst_ref, _redir_drop);
}

t_redirtype	token_to_redirtype(const t_token *t)
{
	if (t->t == TOKEN_REDIR_IN)
		return (REDIR_IN);
	if (t->t == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	if (t->t == TOKEN_REDIR_HDOC)
		return (REDIR_HDOC);
	if (t->t == TOKEN_REDIR_APPEND)
		return (REDIR_APPEND);
	return (-1);
}
