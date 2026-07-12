/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:32:56 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/11 18:46:27 by doyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H
# include <stdbool.h>
# include "libft.h"

typedef enum e_error		t_error;
typedef struct s_ctx		t_ctx;
typedef struct s_env		t_env;
typedef enum e_tokentype	t_tokentype;
typedef struct s_token		t_token;

/* ---------------------------------- */
/* error                              */
/* ---------------------------------- */

enum e_error
{
	ERROR_OK,
	ERROR_INTERNAL,
	ERROR_DEBUG,
	ERROR_SYN,
};

//	TODO: implement detailed error log
void	error_log(t_error err);

/* ---------------------------------- */
/* ctx                                */
/* ---------------------------------- */

struct s_env
{
	char	*key;
	char	*val;
};

t_env	*env_new(const char *s);
void	env_clear(t_env *env_ref);
void	env_drop(t_env *env_ref);
void	env_log(const t_env *env_ref, size_t indent);
t_error	envlst_init(t_ctx *c_ref, t_lst *envlst_ref, char **envp);
void	envlst_drop(t_lst *envlst_ref);
void	envlst_log(const t_lst *envlst_ref, size_t indent);

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
void	ctx_drop(t_ctx *c_ref);
void	ctx_drop_session(t_ctx *c_ref);
char	*ctx_getenv(const t_ctx *c_ref, const char *key);
t_error	ctx_expand(t_ctx *c_ref, char **s);
t_error	geterr(t_ctx *c_ref);
t_error	seterr(t_ctx *c_ref, t_error err);

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

t_token	*token_new(char *s);
void	token_clear(t_token *tok_ref);
void	token_drop(t_token *tok_ref);
bool	token_is_redir(const t_token *tok_ref);
bool	token_is_meta(const t_token *tok_ref);
bool	token_is_word(const t_token *tok_ref);
void	token_log(const t_token *tok_ref, size_t indent);
void	toklst_drop(t_lst *toklst_ref);
void	toklst_log(const t_lst *toklst_ref, size_t indent);

/* ---------------------------------- */
/* util                               */
/* ---------------------------------- */

void	log_indent(size_t indent);

#endif // DEF_H
