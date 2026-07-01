/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:40:19 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/01 14:15:20 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdbool.h>
#include "main.h"
#include "prom.h"

int	main(void)
{
	char	*input;
	t_lst	cmdlst;
	//t_lst	exelst;

	while (true)
	{
		input = prom();
		cmdlst = parse(input);
		free(input);
		//exelst = prep(&cmdlst);
		//exec(exelst);
	}
}
