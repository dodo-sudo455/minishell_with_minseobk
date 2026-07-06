/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stubs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:59:32 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 16:00:22 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ctx_expand(const t_ctx *c_ref, const char *key)
{
	(void)c_ref;
	(void)key;
	return (NULL);
}

t_error	parse_expand(t_ctx *c_ref, t_lst *toklst_ref)
{
	(void)c_ref;
	(void)toklst_ref;
	return (ERROR_OK);
}

t_error	parse_quote(t_ctx *c_ref, t_lst *toklst_ref)
{
	(void)c_ref;
	(void)toklst_ref;
	return (ERROR_OK);
}
