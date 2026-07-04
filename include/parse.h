/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:15:38 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/04 17:39:48 by minseobk         ###   ########.fr       */
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
/* parse                              */
/* ---------------------------------- */

t_error	parse(t_ctx *c_ref, const char *input, t_lst *toklst_ref);
t_error	parse_tokenize(t_ctx *c_ref, const char *input, t_lst *toklst_ref);
// expand token only with WORD
t_error	parse_expand(t_ctx *c_ref, t_lst *toklst_ref);
// 1. check quote syntax, 2. remove quote
t_error	parse_quote(t_ctx *c_ref, t_lst *toklst_ref);

#endif // PARSE_H
