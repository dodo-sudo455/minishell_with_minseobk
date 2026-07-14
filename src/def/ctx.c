/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:49:22 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/14 14:12:42 by doyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

t_ctx	ctx_make(void)
{
	t_ctx	c;

	ft_memset(&c, 0, sizeof(t_ctx));
	return (c);
}

t_error	ctx_init(t_ctx *c_ref, char **envp)
{
	ft_memset(c_ref, 0, sizeof(t_ctx));
	c_ref->envp = envp;
	if (envlst_init(c_ref, &c_ref->envlst, envp) != ERROR_OK)
		return (geterr(c_ref));
	c_ref->hdlst = ft_lst_make();
	return (ERROR_OK);
}

void	ctx_drop(t_ctx *c_ref)
{
	if (c_ref->input)
		free(c_ref->input);
	envlst_drop(&c_ref->envlst);
	ft_lst_clear(&c_ref->hdlst);
	ft_memset(c_ref, 0, sizeof(t_ctx));
}

// TODO: unlink hdoclst
void	ctx_clear_session(t_ctx *c_ref)
{
	if (c_ref->input)
	{
		free(c_ref->input);
		c_ref->input = NULL;
	}
}
