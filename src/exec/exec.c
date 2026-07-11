/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:38:14 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/11 19:26:15 by doyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static t_error	_handle_redir(t_ctx *c_ref, t_cmd *cmd_ref, t_lst *nod_ref)
{
	t_token	*tok_ref;
	t_redir	*red_ref;

	tok_ref = nod_ref->data;
	nod_ref = nod_ref->next;
	tok_ref = nod_ref->data;
	if (!token_is_word(tok_ref))
		return (error_log(ERROR_SYN), seterr(c_ref, ERROR_SYN));
	red_ref = redir_new(token_to_redirtype(tok_ref->t), tok_ref->s);
	if (!red_ref)
		return (error_log(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	if (ft_lst_push(&cmd_ref->redlst, red_ref) != 0)
		return (error_log(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}

static t_error	_handle_word(t_ctx *c_ref, t_cmd *cmd_ref, t_lst *nod_ref)
{
	t_token	*tok_ref;
	char	*fname;

	tok_ref = nod_ref->data;
	fname = ft_strdup(tok_ref->s);
	if (!fname)
		return (error_log(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	if (ft_lst_push(&cmd_ref->arglst, fname) != 0)
		return (free(fname), error_log(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}

t_error	exec_parse(t_ctx *c_ref, const t_lst *toklst_ref, t_lst *cmdlst_ref)
{
	t_cmd	*cmd_ref;
	t_lst	*nod_ref;
	t_token	*tok_ref;
	char	*fname;

	*cmdlst_ref = ft_lst_make();
	cmd_ref = cmd_new();
	nod_ref = ft_lst_first(toklst_ref);
	while (nod_ref)
	{
		tok_ref = nod_ref->data;
		if (token_is_redir(tok_ref))
		{
			if (_handle_redir(c_ref, cmd_ref, nod_ref) != ERROR_OK)
				return (cmd_drop(cmd_ref), cmdlst_drop(cmdlst_ref), ERROR_INTERNAL);
			nod_ref = nod_ref->next;
		}
		else if (token_is_word(tok_ref))
		{
			if (_handle_word(c_ref, cmd_ref, nod_ref) != ERROR_OK)
				return (cmd_drop(cmd_ref), cmdlst_drop(cmdlst_ref), ERROR_INTERNAL);
		}
		else if (tok_ref->t == TOKEN_PIPE)
		{
			if (ft_lst_push(cmdlst_ref, cmd_ref) != 0)
				return (cmd_drop(cmd_ref), cmdlst_drop(cmdlst_ref),
					error_log(ERROR_INTERNAL), seterr(c_ref, ERROR_INTERNAL));
		}
		else
			return (cmd_drop(cmd_ref), cmdlst_drop(cmdlst_ref),
					error_log(ERROR_DEBUG), seterr(c_ref, ERROR_DEBUG));		
		nod_ref = nod_ref->next;
	}
	ft_lst_push(cmdlst_ref, cmd_ref);
	return (ERROR_OK);
}
