/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyelee <doyelee@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:46:36 by doyelee           #+#    #+#             */
/*   Updated: 2026/07/11 18:49:20 by doyelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def.h"

void	error_log(t_error err)
{
	char	to_char;

	to_char = err + '0';
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, &to_char, 1);
	write(STDERR_FILENO, "\n", 1);
}
