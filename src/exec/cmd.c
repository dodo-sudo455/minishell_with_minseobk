/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:04:08 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 20:26:34 by minseobk         ###   ########.fr       */
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

void	cmd_log(const t_cmd *cmd_ref, size_t indent)
{
	const t_lst	*nod_ref;

	log_indent(indent);
	printf("{\n");
	log_indent(indent + 1);
	printf("arglst: [");
	nod_ref = cmd_ref->arglst.next;
	while (nod_ref && nod_ref != &cmd_ref->arglst)
	{
		printf("%s", (char *)nod_ref->data);
		if (nod_ref->next && nod_ref->next != &cmd_ref->arglst)
			printf(", ");
		nod_ref = nod_ref->next;
	}
	printf("]\n");
	log_indent(indent + 1);
	printf("redlst: ");
	redlst_log(&cmd_ref->redlst, 0);
	log_indent(indent);
	printf("}\n");
}
