/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:18:20 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/03 17:02:58 by minseobk         ###   ########.fr       */
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
	REDIR_APPEND,
};

struct s_redir
{
	t_redirtype	type;
	char		*fname;
};

struct s_cmd
{
	t_lst	arglst;
	t_lst	redlst;
};

t_error	exec(t_ctx *c_ref, t_lst *toklst_ref);
t_error	exec_redir(t_ctx *c_ref, t_tokentype t, char *s);
t_error	exec_run(t_ctx*c_ref, int fd[2], t_lst *arglst_ref);


/*
exec(toklst):

	cmdlst := make_cmdlst()
	cmd := make_cmd()
	while (!is_empty(toklst)):
		tok := toklst.pop()
		if tok.type == TOKEN_REDIR:
			next_tok := toklst.pop()
			
			if tok.type == TOKEN_REDIR_HDOC:
				redir := handle_heredoc(tok.type, next_tok.str)
			else
				redir := make_redir(tok.type, next_tok.str)
			
			cmd.add_redir(redir)
		
		if tok.type == TOKEN_WORD:
			cmd.add_arg(tok.str)
		
		if tok.type == TOKEN_PIPE:
			cmdlst.add(cmd)
			cmd := make_cmd()

	cmdlst.add(cmd)
	
	for each cmd in cmdlst:
		run_cmd(cmd)

	wait_cmd()
	unlink_hdoc(cmdlst)

*/

#endif // EXEC_H
