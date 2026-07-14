/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:38:14 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 20:31:35 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_error	_handle_redir(t_ctx *c_ref, t_cmd *cmd_ref, t_lst *nod_ref)
{
	t_token	*tok_ref[2];
	t_redir	*red_ref;

	tok_ref[0] = nod_ref->data;
	nod_ref = nod_ref->next;
	tok_ref[1] = nod_ref->data;
	if (!token_is_word(tok_ref[1]))
		return (logerr(ERROR_SYN), seterr(c_ref, ERROR_SYN));
	red_ref = redir_new(token_to_redirtype(tok_ref[0]), tok_ref[1]->s);
	if (!red_ref)
		return (logerr(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	if (ft_lst_push(&cmd_ref->redlst, red_ref) != 0)
		return (logerr(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}

static t_error	_handle_word(t_ctx *c_ref, t_cmd *cmd_ref, t_lst *nod_ref)
{
	t_token	*tok_ref;
	char	*s;

	tok_ref = nod_ref->data;
	s = ft_strdup(tok_ref->s);
	if (!s)
		return (logerr(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	if (ft_lst_push(&cmd_ref->arglst, s) != 0)
		return (free(s), logerr(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}

static t_error	_handle_pipe(t_ctx *c_ref, t_lst *cmdlst_ref, t_cmd **cmd_ref)
{
	if (ft_lst_push(cmdlst_ref, *cmd_ref) != 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	*cmd_ref = cmd_new();
	if (!*cmd_ref)
		return (geterr(c_ref));
	return (ERROR_OK);
}

static t_error	_parse_node(
	t_ctx *c_ref, t_lst *cmdlst_ref, t_cmd **cmd_ref, t_lst **nod_ref)
{
	t_token	*tok_ref;

	tok_ref = (*nod_ref)->data;
	if (token_is_redir(tok_ref))
	{
		if (_handle_redir(c_ref, *cmd_ref, *nod_ref) != ERROR_OK)
			return (geterr(c_ref));
		*nod_ref = (*nod_ref)->next;
	}
	else if (token_is_word(tok_ref))
	{
		if (_handle_word(c_ref, *cmd_ref, *nod_ref) != ERROR_OK)
			return (geterr(c_ref));
	}
	else if (tok_ref->t == TOKEN_PIPE)
		return (_handle_pipe(c_ref, cmdlst_ref, cmd_ref));
	else
		return (seterr(c_ref, ERROR_DEBUG));
	return (ERROR_OK);
}

t_error	exec_parse(t_ctx *c_ref, const t_lst *toklst_ref, t_lst *cmdlst_ref)
{
	t_cmd	*cmd_ref;
	t_lst	*nod_ref;

	*cmdlst_ref = ft_lst_make();
	cmd_ref = cmd_new();
	nod_ref = toklst_ref->next;
	while (nod_ref && nod_ref != toklst_ref)
	{
		if (_parse_node(c_ref, cmdlst_ref, &cmd_ref, &nod_ref) != ERROR_OK)
			return (cmd_drop(cmd_ref), cmdlst_clear(cmdlst_ref),
				logerr(geterr(c_ref)), geterr(c_ref));
		nod_ref = nod_ref->next;
	}
	if (ft_lst_push(cmdlst_ref, cmd_ref) != 0)
		return (cmd_drop(cmd_ref), cmdlst_clear(cmdlst_ref),
			logerr(geterr(c_ref)), geterr(c_ref));
	return (ERROR_OK);
}
