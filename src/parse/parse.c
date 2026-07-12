/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:17:07 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/12 20:00:09 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_error	parse(t_ctx *c_ref, const char *input, t_lst *toklst_ref)
{
	if (parse_tokenize(c_ref, input, toklst_ref) != ERROR_OK)
		return (toklst_clear(toklst_ref), geterr(c_ref));
	if (parse_expand(c_ref, toklst_ref) != ERROR_OK)
		return (toklst_clear(toklst_ref), geterr(c_ref));
	if (parse_quote(c_ref, toklst_ref) != ERROR_OK)
		return (toklst_clear(toklst_ref), geterr(c_ref));
	return (ERROR_OK);
}
