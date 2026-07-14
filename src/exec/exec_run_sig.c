/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_run_sig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:31:27 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/14 17:45:28 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <signal.h>
#include <sys/signal.h>

/**
 *	DESCRIPTION
 *
 *		- sigint: ign
 *		- sigquit: ign
 *		- sigD: -
 */
t_error	exec_run_sig_parent(t_ctx *c_ref)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) < 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGINT, &sa, NULL) < 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sa, NULL) < 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}

t_error	exec_run_sig_child(t_ctx *c_ref)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) < 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	sa.sa_flags = 0;
	sa.sa_handler = SIG_DFL;
	if (sigaction(SIGINT, &sa, NULL) < 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	sa.sa_handler = SIG_DFL;
	if (sigaction(SIGQUIT, &sa, NULL) < 0)
		return (seterr(c_ref, ERROR_INTERNAL));
	return (ERROR_OK);
}
