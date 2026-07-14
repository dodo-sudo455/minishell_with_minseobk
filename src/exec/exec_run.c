/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:22:10 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/14 18:15:50 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

static pid_t	*_get_pidarr(const t_lst *cmdlst_ref)
{
	pid_t	*arr;

	arr = malloc(sizeof(pid_t) * ft_lst_size(cmdlst_ref));
	ft_memset(arr, 0, sizeof(pid_t) * ft_lst_size(cmdlst_ref));
	return (arr);
}

static t_error	_wait_pidarr(
	t_ctx *c_ref, const pid_t *pidarr, size_t n, int *stat_ref)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (waitpid(pidarr[i], stat_ref, NULL) < 0)
			return (seterr(c_ref), ERROR_INTERNAL);
		i += 1;
	}
	return (ERROR_OK);
}

static t_error	_run_child(t_ctx *c_ref, const t_cmd *cmd_ref, int pipefd[2])
{
	exec_run_sig_child(c_ref);
	if 
}

/**
 *	DESCRIPTION
 *
 *		For each cmd:
 *			- pipe
 *			- open redir
 *			- exec
 */
t_error	exec_run(t_ctx *c_ref, const t_lst *cmdlst_ref)
{
	int		prev_read_fd;
	t_lst	*nod_ref;
	t_cmd	*cmd_ref;
	int		pipe_fd[2];
	pid_t	*pidarr;
	size_t	i;
	int		stat;

	if (exec_run_sig_parent(c_ref) != ERROR_OK)
		return (geterr(c_ref));
	prev_read_fd = 0;
	nod_ref = cmdlst_ref->next;
	pidarr = _get_pidarr(cmdlst_ref);
	if (!pidarr)
		return (seterr(c_ref, ERROR_INTERNAL));
	i = 0;
	while (nod_ref != cmdlst_ref)
	{
		cmd_ref = nod_ref->data;
		if (nod_ref->next && pipe(pipe_fd) != 0)
			return (seterr(c_ref, ERROR_INTERNAL));
		pidarr[i] = fork();
		if (pidarr[i] == 0 && _run_child(c_ref, cmd_ref, pipe_fd) != ERROR_OK)
			return (geterr(c_ref));
		if (prev_read_fd != 0)
			close(prev_read_fd);
		if (nod_ref->next)
		{
			prev_read_fd = pipe_fd[0];
			close(pipe_fd[1]);
		}
		nod_ref = nod_ref->next;
		i += 1;
	}
	if (_wait_pidarr(c_ref, pidarr, i, &stat) != ERROR_OK)
		return (geterr(c_ref));
	if (stat != 0)
	{
	}
	return (ERROR_DEBUG);
}
