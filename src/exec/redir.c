/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:51:52 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/12 20:11:42 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_redir	*redir_new(t_redirtype type, const char *s)
{
	t_redir	*red_ref;

	red_ref = malloc(sizeof(t_redir));
	if (!red_ref)
		return (NULL);
	red_ref->t = type;
	red_ref->s = ft_strdup(s);
	if (!red_ref->s)
	{
		free(red_ref);
		return (NULL);
	}
	return (red_ref);
}

void	redir_drop(t_redir *red_ref)
{
	if (!red_ref)
		return ;
	free(red_ref->s);
	free(red_ref);
}

static const char	*_redirtype_to_str(t_redirtype t)
{
	if (t == REDIR_IN)
		return ("REDIR_IN");
	if (t == REDIR_OUT)
		return ("REDIR_OUT");
	if (t == REDIR_HDOC)
		return ("REDIR_HDOC");
	if (t == REDIR_APPEND)
		return ("REDIR_APPEND");
	return ("?");
}

void	redir_log(const t_redir *red_ref)
{
	printf("(%s, %s)", _redirtype_to_str(red_ref->t), red_ref->s);
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
