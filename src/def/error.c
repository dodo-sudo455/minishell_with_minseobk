/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:46:36 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/12 17:31:07 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

void	logerr(t_error err)
{
	char	to_char;

	to_char = err + '0';
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, &to_char, 1);
	write(STDERR_FILENO, "\n", 1);
}
