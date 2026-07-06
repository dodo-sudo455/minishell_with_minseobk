/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:07:54 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 16:08:47 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

t_error	geterr(t_ctx *c_ref)
{
	return (c_ref->err);
}

t_error	seterr(t_ctx *c_ref, t_error err)
{
	c_ref->err = err;
	return (err);
}
