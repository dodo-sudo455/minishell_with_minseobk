/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:51:52 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/12 13:57:37 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_redir	*redir_new(t_redirtype type, const char *s)
{
	t_redir	*redir_ref;

	redir_ref = malloc(sizeof(t_redir));
	if (!redir_ref)
		return (NULL);
	redir_ref->t = type;
	redir_ref->s = ft_strdup(s);
	if (!redir_ref->s)
	{
		free(redir_ref);
		return (NULL);
	}
	return (redir_ref);
}
