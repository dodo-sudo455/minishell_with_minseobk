/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:40:19 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/02 16:57:15 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdbool.h>
#include "main.h"
#include "prom.h"
#include "parse.h"
#include "exec.h"

int	main(int argc, char **argv, char **envp)
{
	t_ctx	ctx;
	char	*input;
	t_list	*toklst;
	//t_lst	exelst;

	if (ctx_init(&ctx, envp) != ERROR_OK)
		return (geterr(&ctx));
	while (true)
	{
		input = prom();
		if (parse(&ctx, input, &toklst) != ERROR_OK)
			return (free(input), geterr(&ctx));
		free(input);
		if (exec(&ctx, ))
	}
}
