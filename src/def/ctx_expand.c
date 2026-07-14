/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:27:04 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 17:26:54 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

/**
 *	DESCRIPTION
 *
 *		Count env var key length and duplicate it.
 */
static char	*_extract_var_key(const char *str, size_t *i)
{
	size_t	start;
	size_t	len;

	start = *i;
	if (str[start] == '?')
		len = 1;
	else
	{
		len = 0;
		while (ft_isalnum(str[start + len]) || str[start + len] == '_')
			len++;
	}
	*i += len;
	return (ft_strndup(str + start, len));
}

/**
 *	DESCRIPTION
 *
 *		Handle dollar character in `str`.
 */
static t_error	_expand_var(
	t_ctx *c_ref, t_vec *vec, const char *str, size_t *i)
{
	char	*key;
	char	*val;

	(*i)++;
	if (!ft_isalpha(str[*i]) && str[*i] != '_' && str[*i] != '?')
	{
		if (ft_vec_push(vec, '$') != 0)
			return (seterr(c_ref, ERROR_INTERNAL));
		return (ERROR_OK);
	}
	key = _extract_var_key(str, i);
	if (!key)
		return (seterr(c_ref, ERROR_INTERNAL));
	val = ctx_getenv(c_ref, key);
	free(key);
	if (!val)
		return (seterr(c_ref, ERROR_INTERNAL));
	if (ft_vec_push_n(vec, val, ft_strlen(val)) != 0)
		return (free(val), seterr(c_ref, ERROR_INTERNAL));
	return (free(val), ERROR_OK);
}

static int	_update_quote_state(int state, char c)
{
	if (c == '\'' && state != 2)
	{
		if (state == 1)
			return (0);
		return (1);
	}
	if (c == '"' && state != 1)
	{
		if (state == 2)
			return (0);
		return (2);
	}
	return (state);
}

// expand all env vars and replace the string in-place.
t_error	ctx_expand(t_ctx *c_ref, char **s)
{
	t_vec	vec;
	int		state;
	size_t	i;

	vec = ft_vec_make(ft_strlen(*s));
	state = 0;
	i = 0;
	while ((*s)[i])
	{
		state = _update_quote_state(state, (*s)[i]);
		if ((*s)[i] == '$' && state != 1)
		{
			if (_expand_var(c_ref, &vec, *s, &i) != ERROR_OK)
				return (ft_vec_clear(&vec), c_ref->err);
			continue ;
		}
		if (ft_vec_push(&vec, (*s)[i++]) != 0)
			return (ft_vec_clear(&vec), seterr(c_ref, ERROR_INTERNAL));
	}
	free(*s);
	*s = ft_vec_to_str(&vec);
	ft_vec_clear(&vec);
	if (!*s)
		return (seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}
