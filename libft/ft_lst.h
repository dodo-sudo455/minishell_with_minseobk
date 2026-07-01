/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:29:01 by minseobk          #+#    #+#             */
/*   Updated: 2026/06/14 17:40:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H
# include "_libft.h"
# include <stdbool.h>

typedef struct s_lstnode	t_lstnode;
typedef struct s_lst		t_lst;
typedef struct s_lstiter	t_lstiter;
typedef t_lst				t_slst;
typedef struct s_lstiter	t_slstiter;

/* ---------------------------------- */
/* listnod                            */
/* ---------------------------------- */

typedef struct s_lstnode
{
	void		*data;
	t_lstnode	*prev;
	t_lstnode	*next;
}	t_lstnode;

//	ft_lstnode.c
t_lstnode		*ft_lstnode_new(void *data);
void			*ft_lstnode_con(t_lstnode *nod_ref);

/* ---------------------------------- */
/* list                               */
/* ---------------------------------- */

typedef struct s_lst
{
	int			size;
	t_lstnode	*head;
	t_lstnode	*tail;
}	t_lst;

//	ft_lst.c
t_lst			ft_lst_make(void);
void			ft_lst_drop(t_lst *l_ref);
void			ft_lst_drop_with(t_lst *l_ref, void (*del)(void *));
bool			ft_lst_is_empty(const t_lst *l_ref);

//	ft_lst_push.c
int				ft_lst_push(t_lst *l_ref, void *data);
int				ft_lst_push_front(t_lst *l_ref, void *data);

//	ft_lst_pop.c
void			*ft_lst_pop(t_lst *l_ref);
void			*ft_lst_pop_front(t_lst *l_ref);

/* ---------------------------------- */
/* lstiter                            */
/* ---------------------------------- */

typedef struct s_lstiter
{
	t_lstnode	*nod_ref;
	int			i;
	const int	*n_ref;
}	t_lstiter;

t_lstiter		ft_lstiter_make(const t_lst *l_ref);
bool			ft_lstiter_has_next(const t_lstiter *i_ref);
bool			ft_lstiter_has_prev(const t_lstiter *i_ref);
void			*ft_lstiter_next(t_lstiter *i_ref);
void			*ft_lstiter_prev(t_lstiter *i_ref);

#endif // FT_LST_H
