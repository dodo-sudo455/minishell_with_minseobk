/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:18:20 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/14 17:53:42 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "libft.h"
# include "def.h"
# include "parse.h"

typedef enum e_redirtype	t_redirtype;
typedef struct s_redir		t_redir;
typedef struct s_cmd		t_cmd;

/* ---------------------------------- */
/* exec                               */
/* ---------------------------------- */

enum e_redirtype
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_HDOC,
	REDIR_APPEND
};

/**
 *	FIELDS
 *		- `t`: redirection typed
 *		- `s`: file name or heredoc delimiter
 */
struct s_redir
{
	t_redirtype	t;
	char		*s;
};

t_redir		*redir_new(t_redirtype type, const char *fname);
void		redir_drop(t_redir *red_ref);
void		redir_log(const t_redir *red_ref);
t_redirtype	token_to_redirtype(const t_token *t);
void		redlst_clear(t_lst *redlst_ref);
void		redlst_log(const t_lst *redlst_ref, size_t indent);

struct s_cmd
{
	t_lst	arglst;
	t_lst	redlst;
};

t_cmd		*cmd_new(void);
void		cmd_clear(t_cmd *cmd_ref);
void		cmd_drop(t_cmd *cmd_ref);
void		cmd_log(const t_cmd *cmd_ref, size_t indent);
t_error		cmd_run(t_ctx *c_ref, int fd[2], const t_cmd *cmd_ref);
void		cmdlst_clear(t_lst *cmdlst_ref);
void		cmdlst_log(const t_lst *cmdlst_ref, size_t indent);

t_error		exec(t_ctx *c_ref, const t_lst *toklst_ref, t_lst *cmdlst_ref);
t_error		exec_parse(t_ctx *c_ref,
				const t_lst *toklst_ref, t_lst *cmdlst_ref);
t_error		exec_redir(t_ctx *c_ref, t_lst *cmdlst_ref);
t_error		exec_pipe(t_ctx *c_ref, t_lst *cmdlst_ref);
t_error		exec_run(t_ctx*c_ref, const t_lst *cmdlst_ref);
t_error		exec_run_sig_parent(t_ctx *c_ref);
t_error		exec_run_sig_child(t_ctx *c_ref);

/*
exec(toklst):
	# ---------------------------------------------------------
	# parse
	# ---------------------------------------------------------
	cmdlst := make_cmdlst()
	cmd := make_cmd()

	while (!is_empty(toklst)):
		tok := toklst.pop()
		if tok.type == TOKEN_REDIR:
			next_tok := toklst.pop()
			if next_tok.type != WORD:
				panic()

			redir := make_redir(tok.type, next_tok.str)
			cmd.add_redir(redir)
		
		elif tok.type == TOKEN_WORD:
			cmd.add_arg(tok.str)
		
		elif tok.type == TOKEN_PIPE:
			cmdlst.add(cmd)
			cmd := make_cmd()

	cmdlst.add(cmd)
	
	# ---------------------------------------------------------
	# heredoc
	# ---------------------------------------------------------
	if not gather_all_heredocs(cmdlst):
		unlink_hdoc(cmdlst)
		set_exit_status(130)
		return

	# ---------------------------------------------------------
	# exec
	# ---------------------------------------------------------
	for each cmd in cmdlst:
		run_cmd(cmd)

	# ---------------------------------------------------------
	# clear
	# ---------------------------------------------------------
	wait_all_cmds()
	unlink_hdoc(cmdlst)
*/

#endif // EXEC_H
