/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:33:43 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/14 16:30:29 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prom.h"
#include <signal.h>
#include <sys/signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

static void	sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/**
 *	TODO
 *
 *		- signal vs sigaction
 *		- readline(prompt string)
 */
char	*prom(void)
{
	struct sigaction	sa;
	char				*input;

	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
		{
			printf("exit\n");
			exit(1);
		}
		if (*input)
			break ;
		free(input);
	}
	add_history(input);
	return (input);
}
