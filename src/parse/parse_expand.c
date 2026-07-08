/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:16:53 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/08 12:41:06 by doyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*
 *	buf: 실제 문자열
 *	len: 현재까지 채워진 길이(NULL 제외)
 *	cap: buf에 할당된 총 용량
*/
typedef struct s_sbuf
{
	char	*buf;
	size_t	len;
	size_t	cap;
}	t_sbuf;

// s에서 n글자를 sb에 이어붙임
static bool	_sbuf_append(t_sbuf *sb, const char *s, size_t n)
{
	char	*tmp;
	size_t	newcap;

	if (sb->len + n + 1 <= sb->cap)
	{
		ft_memcpy(sb->buf + sb->len, s, n);
		sb->len += n;
		sb->buf[sb->len] = '\0';
		return (true);
	}
	newcap = (sb->cap + n + 1) * 2;
	tmp = malloc(newcap);
	if (!tmp)
		return (false);
	if (sb->buf)
	{
		ft_memcpy(tmp, sb->buf, sb->len);
		free(sb->buf);
	}
	sb->buf = tmp;
	sb->cap = newcap;
	ft_memcpy(sb->buf + sb->len, s, n);
	sb->len += n;
	sb->buf[sb->len] = '\0';
	return (true);
}

// 쉘 변수 이름 규칙
// 첫 글자: 알파벳이나 _만 가능
static inline bool	_is_var_start(char c)
{
	return (ft_isalpha(c) || c == '_');
}

// 알파벳, 숫자, _ 가능
static inline bool	_is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

// 환경 변수에서 name 찾아 값 반환
static char	*_get_var_value(t_ctx *c_ref, const char *name)
{
	char	*val;
	t_lst	*node;
	t_env	*env_ref;

	val = getenv(name);
	if (val)
		return (ft_strdup(val));
	node = c_ref->envlst.next;
	while (node && node != &c_ref->envlst)
	{
		env_ref = node->data;
		if (!ft_strcmp(env_ref->key, name))
			return (ft_strdup(env_ref->val));
		node = node->next;
	}
	return (ft_strdup(""));
}

static bool	_try_expand(t_ctx *c_ref, t_sbuf *sb, const char *s, size_t *i)
{
	size_t	start;
	char	*name;
	char	*val;

	start = *i + 1;
	if (!_is_var_start(s[start]))
	{
		*i += 1;
		return (_sbuf_append(sb, s + *i - 1, 1));
	}
	*i = start;
	while (_is_var_char(s[*i]))
		*i += 1;
	name = ft_strndup(s + start, *i - start);
	if (!name)
		return (false);
	val = _get_var_value(c_ref, name);
	free(name);
	if (!val)
		return (false);
	if (!_sbuf_append(sb, val, ft_strlen(val)))
		return (free(val), false);
	free(val);
	return (true);
}

// state 0=NONE, 1=SIGLE, 2=DOUBLE
static t_error	_expand_str(t_ctx *c_ref, const char *s, t_sbuf *sb)
{
	size_t	i;
	int		state;

	i = 0;
	state = 0;
	while (s[i])
	{
		if (s[i] == '\'' && state != 2)
			state = (state == 1) ? 0 : 1;
		else if (s[i] == '"' && state != 1)
			state = (state == 2) ? 0: 2;
		if (s[i] == '$' && state != 1)
		{
			if (!_try_expand(c_ref, sb, s, &i))
				return (seterr(c_ref, ERROR_INTERNAL));
			continue ;
		}
		if (!_sbuf_append(sb, s + i, 1))
			return (seterr(c_ref, ERROR_INTERNAL));
		i += 1;
	}
	return (ERROR_OK);
}

static void	_token_del(void *ref)
{
	t_token	*tok_ref;

	tok_ref = ref;
	token_drop(tok_ref);
	free(tok_ref);
}

static void	_drop_token_node(t_lst *node)
{
	ft_lst_remove_with(node, _token_del);
}

static t_error	_expand_node(t_ctx *c_ref, t_lst *node)
{
	t_token	*tok_ref;
	t_sbuf	sb;

	tok_ref = node->data;
	if (!token_is_word(tok_ref))
		return (ERROR_OK);
	ft_memset(&sb, 0, sizeof(sb));
	if (_expand_str(c_ref, tok_ref->s, &sb) != ERROR_OK)
		return (free(sb.buf), geterr(c_ref));
	free(tok_ref->s);
	if (!sb.buf)
		sb.buf = ft_strdup("");
	tok_ref->s = sb.buf;
	if (tok_ref->s[0] == '\0' && !tok_ref->has_quote)
		return (_drop_token_node(node), ERROR_OK);
	return (ERROR_OK);
}

t_error	parse_expand(t_ctx *c_ref, t_lst *toklst_ref)
{
	t_lst	*node;
	t_lst	*next;

	node = toklst_ref->next;
	while (node && node != toklst_ref)
	{
		next = node->next;
		if (_expand_node(c_ref, node) != ERROR_OK)
			return (geterr(c_ref));
		node = next;
	}
	return (ERROR_OK);
}
