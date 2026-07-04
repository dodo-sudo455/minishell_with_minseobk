/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:32:56 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/04 17:37:42 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

typedef enum e_error	t_error;
typedef struct s_ctx	t_ctx;
typedef struct s_env	t_env;

/* ---------------------------------- */
/* ctx                                */
/* ---------------------------------- */

struct s_env
{
	char	*key;
	char	*val;
};

struct s_ctx
{
	t_error		err;
	char		*input;
	char		**envp;
	t_lst		envlst;
	t_lst		hdoclst;
};

t_ctx	ctx_make(void);
t_error	ctx_init(t_ctx *c_ref, char **envp);
char	*ctx_expand(const t_ctx *c_ref, const char *key);
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
	ERROR_SYN,
	ERROR_SYN_QUOTE,
	ERROR_SYN_PIPE,
	ERROR_SYN_REDIR,
};

/* ---------------------------------- */
/* token                              */
/* ---------------------------------- */

enum e_tokentype
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_HDOC,
	TOKEN_REDIR_APPEND,
};

struct s_token
{
	t_tokentype	t;
	char		*s;
	bool		has_quote;
};

t_token	token_make(char *s);
void	token_drop(t_token *tok_ref);
bool	token_is_redir(const t_token *tok_ref);
bool	token_is_meta(const t_token *tok_ref);
void	toklst_clear(t_lst **lst_ref);

#endif // DEF_H
