/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:53:47 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 16:20:28 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

t_env	*env_make(const char *s)
{
	t_env	*env_ref;
	char	*pos;

	env_ref = malloc(sizeof(t_env));
	if (!env_ref)
		return (NULL);
	ft_memset(env_ref, 0, sizeof(t_env));
	pos = ft_strchr(s, '=');
	if (pos)
	{
		env_ref->key = ft_strndup(s, pos - s);
		if (!env_ref->key)
			return (env_drop(env_ref), free(env_ref), NULL);
		env_ref->val = ft_strdup(pos + 1);
		if (!env_ref->val)
			return (env_drop(env_ref), free(env_ref), NULL);
	}
	else
	{
		env_ref->key = ft_strdup(s);
		if (!env_ref->key)
			return (env_drop(env_ref), free(env_ref), NULL);
		env_ref->val = NULL;
	}
	return (env_ref);
}

void	env_drop(t_env *env_ref)
{
	if (env_ref->key)
		free(env_ref->key);
	if (env_ref->val)
		free(env_ref->val);
	ft_memset(env_ref, 0, sizeof(t_env));
}

void	env_log(const t_env *env_ref, size_t indent)
{
	log_indent(indent);
	printf("{\n");
	log_indent(indent + 1);
	printf("key: %s\n", env_ref->key);
	log_indent(indent + 1);
	printf("val: %s\n", env_ref->val);
	log_indent(indent);
	printf("}\n");
}
