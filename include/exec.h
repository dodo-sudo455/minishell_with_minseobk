/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:18:20 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/03 14:31:47 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "libft.h"
# include "def.h"
# include "parse.h"

/* ---------------------------------- */
/* exec                               */
/* ---------------------------------- */

t_error	exec(t_ctx *c_ref, t_list *toklst_ref);
t_error	exec_cmd(t_ctx *c_ref, t_list *toklst_ref,
			int fd[2], t_list *arglst_ref);
t_error	exec_redir(t_ctx *c_ref, t_tokentype t, char *s);
t_error	exec_run(t_ctx*c_ref, int fd[2], t_list *arglst_ref);

/*
exec():
	pid = fork();
	if (pid == 0)
	{
		dup2();
		dup2();
		execve();
	}
	close(fd_in);
	close(fd_out);
*/

#endif // EXEC_H
