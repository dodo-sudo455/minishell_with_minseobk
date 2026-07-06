/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:35:24 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/06 15:44:24 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	*_join_args(int argc, char **argv)
{
	char	*input;
	char	*temp;
	int		i;

	input = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(input, argv[i]);
		free(input);
		input = temp;
		if (i < argc - 1)
		{
			temp = ft_strjoin(input, " ");
			free(input);
			input = temp;
		}
		i++;
	}
	return (input);
}

int	main(int argc, char **argv)
{
	t_ctx	c;
	t_lst	toklst;
	char	*input;

	if (argc < 2)
		return (0);
	input = _join_args(argc, argv);
	c = ctx_make();
	toklst = ft_lst_make();
	parse_tokenize(&c, input, &toklst);
	toklst_log(&toklst, 0);
	free(input);
	toklst_drop(&toklst);
	return (0);
}
