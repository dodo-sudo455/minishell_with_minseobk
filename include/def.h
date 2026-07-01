/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:32:56 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/01 14:35:21 by minseobk         ###   ########.fr       */
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
};

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
