/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:04:08 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 17:26:54 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_cmd	*cmd_new(void)
{
	t_cmd	*cmd_ref;

	cmd_ref = malloc(sizeof(t_cmd));
	if (!cmd_ref)
		return (NULL);
	cmd_ref->arglst = ft_lst_make();
	cmd_ref->redlst = ft_lst_make();
	return (cmd_ref);
}

void	cmd_clear(t_cmd *cmd_ref)
{
	if (!cmd_ref)
		return ;
	ft_lst_clear(&cmd_ref->arglst);
	redlst_clear(&cmd_ref->redlst);
	ft_memset(cmd_ref, 0, sizeof(t_cmd));
}

void	cmd_drop(t_cmd *cmd_ref)
{
	if (!cmd_ref)
		return ;
	cmd_clear(cmd_ref);
	free(cmd_ref);
}

static void	_cmd_drop(void *ref)
{
	cmd_drop((t_cmd *)ref);
}

void	cmdlst_clear(t_lst *cmdlst_ref)
{
	ft_lst_clear_with(cmdlst_ref, _cmd_drop);
}
