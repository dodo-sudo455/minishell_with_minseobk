/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:51:29 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 16:21:33 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

t_error	envlst_init(t_ctx *c_ref, t_lst *envlst_ref, char **envp)
{
	t_env	*env_ref;

	while (*envp)
	{
		env_ref = env_make(*envp);
		if (!env_ref)
			return (envlst_drop(envlst_ref), seterr(c_ref, ERROR_INTERNAL));
		if (ft_lst_push(envlst_ref, env_ref) != 0)
			return (env_drop(env_ref),
				free(env_ref),
				envlst_drop(envlst_ref),
				seterr(c_ref, ERROR_INTERNAL));
		envp += 1;
	}
	return (ERROR_OK);
}

static void	_drop_env(void *data)
{
	env_drop(data);
	free(data);
}

void	envlst_drop(t_lst *envlst_ref)
{
	ft_lst_drop_with(envlst_ref, _drop_env);
}

void	envlst_log(const t_lst *envlst_ref, size_t indent)
{
	const t_lst	*nod_ref;

	log_indent(indent);
	printf("[\n");
	nod_ref = envlst_ref->next;
	while (nod_ref && nod_ref != envlst_ref)
	{
		env_log(nod_ref->data, indent + 1);
		nod_ref = nod_ref->next;
	}
	log_indent(indent);
	printf("]\n");
}
