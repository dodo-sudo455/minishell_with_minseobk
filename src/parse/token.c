/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:29:44 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/02 16:33:23 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	token_make(char *s);

static void	del(t_token *tok_ref)
{
	free(tok_ref->s);
	free(tok_ref);
}

void	toklst_clear(t_list **lst_ref)
{
	ft_lstclear(lst_ref, del);
}
