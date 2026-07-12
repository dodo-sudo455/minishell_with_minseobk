/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:54:15 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 13:38:57 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static inline bool	_is_space(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n');
}

static inline bool	_is_meta(char c)
{
	return (c == '<'
		|| c == '>'
		|| c == '|');
}

/**
 *	DESCRIPTION
 *
 *		 Suppose quote syntax is already check from the
 *		previous step. So there will always be a pair of
 *		quotes.
 */
static size_t	_count_word_len(const char *input, size_t start)
{
	size_t	i;

	i = start;
	while (input[i] && !_is_space(input[i]) && !_is_meta(input[i]))
	{
		if (input[i] == '\'')
		{
			i += 1;
			while (input[i] != '\'')
				i += 1;
			i += 1;
		}
		else if (input[i] == '"')
		{
			i += 1;
			while (input[i] != '"')
				i += 1;
			i += 1;
		}
		else
			i += 1;
	}
	return (i - start);
}

static size_t	_count_token_len(const char *input, size_t i)
{
	if (input[i] == '|')
		return (1);
	if (ft_strncmp(input + i, "<<", 2) == 0)
		return (2);
	if (ft_strncmp(input + i, ">>", 2) == 0)
		return (2);
	if (input[i] == '<')
		return (1);
	if (input[i] == '>')
		return (1);
	return (_count_word_len(input, i));
}

/**
 *	DESCRIPTION
 *
 *		 Parse the input string and store tokens in `toklst_ref`.
 *		Meta characters (e.g. '<', '<<', '|') should also be tokenized.
 */
t_error	parse_tokenize(t_ctx *c_ref, const char *input, t_lst *toklst_ref)
{
	size_t	i;
	size_t	toklen;
	char	*s;
	t_token	*tok_ref;

	i = 0;
	while (input[i])
	{
		if (_is_space(input[i]))
		{
			i += 1;
			continue ;
		}
		toklen = _count_token_len(input, i);
		s = ft_strndup(input + i, toklen);
		if (!s)
			return (toklst_drop(toklst_ref), seterr(c_ref, ERROR_INTERNAL));
		tok_ref = token_new(s);
		if (!tok_ref || ft_lst_push(toklst_ref, tok_ref) != 0)
			return (token_drop(tok_ref),
				toklst_drop(toklst_ref), seterr(c_ref, ERROR_INTERNAL));
		i += toklen;
	}
	return (ERROR_OK);
}
