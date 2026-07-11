/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:51:52 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/11 18:58:29 by doyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_redir	*redir_new(t_redirtype type, const char *fname)
{
	t_redir	*redir_ref;

	redir_ref = malloc(sizeof(t_redir));
	if (!redir_ref)
		return (NULL);
	redir_ref->type = type;
	redir_ref->fname = ft_strdup(fname);
	if (!redir_ref->fname)
	{
		free(redir_ref);
		return (NULL);
	}
	return (redir_ref);
}
