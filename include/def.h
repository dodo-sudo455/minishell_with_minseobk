/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:32:56 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/03 15:45:48 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

typedef enum e_error	t_error;
typedef struct s_ctx	t_ctx;


/* ---------------------------------- */
/* ctx                                */
/* ---------------------------------- */

struct s_ctx
{
	t_error		err;
	char		*input;
	char		**envp;
	t_lst		envlst;
	int			hdoc;
};

t_ctx	ctx_make(void);
t_error	ctx_init(t_ctx *c_ref, char **envp);
t_error	geterr(t_ctx *c_ref);
t_error	seterr(t_ctx *c_ref);

/* ---------------------------------- */
/* error                              */
/* ---------------------------------- */

enum e_error
{
	ERROR_OK,
	ERROR_INTERNAL,
	ERROR_DEBUG,
	ERROR_SYNTAX,
};

#endif // DEF_H
