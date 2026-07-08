/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:17:09 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/08 12:21:06 by doyelee          ###   ########.fr       */
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

static t_error	_strip_quote_str(t_ctx *c_ref, const char *s, t_sbuf *sb)
{
	size_t	i;
	int		state;

	i = 0;
	state = 0;
	while (s[i])
	{
		if (s[i] == '\'' && state != 2)
		{
			state = (state == 1) ? 0 : 1;
			i += 1;
			continue ;
		}
		else if (s[i] == '"' && state != 1)
		{
			state = (state == 2) ? 0: 2;
			i += 1;
			continue ;
		}
		if (!_sbuf_append(sb, s + i, 1))
			return (seterr(c_ref, ERROR_INTERNAL));
		i += 1;
	}
	if (state != 0)
		return (seterr(c_ref, ERROR_SYN_QUOTE));
	return (ERROR_OK);
}

static t_error	_quote_node(t_ctx *c_ref, t_token *tok_ref)
{
	t_sbuf	sb;

	if (!token_is_word(tok_ref))
		return (ERROR_OK);
	ft_memset(&sb, 0, sizeof(sb));
	if (_strip_quote_str(c_ref, tok_ref->s, &sb) != ERROR_OK)
		return (free(sb.buf), geterr(c_ref));
	free(tok_ref->s);
	if (!sb.buf)
		sb.buf = ft_strdup("");
	if (!sb.buf)
		return (seterr(c_ref, ERROR_INTERNAL));
	tok_ref->s = sb.buf;
	return (ERROR_OK);
}

t_error	parse_quote(t_ctx *c_ref, t_lst *toklst_ref)
{
	t_lst	*node;

	node = toklst_ref->next;
	while (node && node != toklst_ref)
	{
		if (_quote_node(c_ref, node->data) != ERROR_OK)
			return (geterr(c_ref));
		node = node->next;
	}
	return (ERROR_OK);
}
