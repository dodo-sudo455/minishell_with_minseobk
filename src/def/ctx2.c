/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:07:54 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/08 16:52:48 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

t_error	geterr(t_ctx *c_ref)
{
	return (c_ref->err);
}

t_error	seterr(t_ctx *c_ref, t_error err)
{
	c_ref->err = err;
	return (err);
}

/**
 *	DESCRIPTION
 *
 *		Look up `ctx.envlst` and return duplicate of value.
 *		If key is not found, return empty string.
 */
char	*ctx_getenv(const t_ctx *c_ref, const char *key)
{
	t_lst	*cur;
	t_env	*env;

	if (!c_ref || !key)
		return (NULL);
	cur = c_ref->envlst.next;
	while (cur && cur != &c_ref->envlst)
	{
		env = cur->data;
		if (ft_strcmp(env->key, (char *)key) == 0)
		{
			if (env->val)
				return (ft_strdup(env->val));
			return (ft_strdup(""));
		}
		cur = cur->next;
	}
	return (ft_strdup(""));
}
