/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stubs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:35:59 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/01 12:39:53 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <unistd.h>
#include <stdlib.h>

char	*prom(void)
{
	return (NULL);
}

t_lst	parse(const char *input)
{
	t_lst	lst;

	(void)input;
	lst.head = NULL;
	lst.tail = NULL;
	lst.size = 0;
	return (lst);
}

t_lst	prep(const t_lst *exelst_ref)
{
	t_lst	lst;

	(void)exelst_ref;
	lst.head = NULL;
	lst.tail = NULL;
	lst.size = 0;
	return (lst);
}

void	exec(t_lst exelst)
{
	(void)exelst;
}
