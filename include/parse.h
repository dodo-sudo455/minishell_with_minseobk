/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:15:38 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/01 14:35:04 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "libft.h"
# include "def.h"

typedef struct s_cmd	t_cmd;

/* ---------------------------------- */
/* parse                              */
/* ---------------------------------- */

struct s_cmd
{
	void	*args;
	void	*redir;
};

t_error	parse(t_ctx *c_ref, const char *input, t_lst *lst_ref);

#endif // PARSE_H
