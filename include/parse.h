/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:15:38 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/02 16:36:06 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "libft.h"
# include "def.h"
# include <stdbool.h>

typedef enum e_tokentype	t_tokentype;
typedef struct s_token		t_token;

/* ---------------------------------- */
/* token                              */
/* ---------------------------------- */

enum e_tokentype
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_HDOC,
	TOKEN_REDIR_APPEND,
};

struct s_token
{
	t_tokentype	t;
	char		*s;
	bool		has_quote;
};

t_token	token_make(char *s);
void	toklst_clear(t_list **lst_ref);

/* ---------------------------------- */
/* parse                              */
/* ---------------------------------- */

t_error	parse(t_ctx *c_ref, const char *input, t_list **toklst_ref);
t_error	parse_tokenize(t_ctx *c_ref, const char *input, t_list **toklst_ref);
bool	parse_is_syntax_ok(const t_list *toklst_ref);
t_error	parse_expand(t_ctx *c_ref, t_list **toklst_ref);
t_error	parse_quote(t_ctx *c_ref, t_list **toklst_ref);

#endif // PARSE_H
