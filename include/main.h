/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:32:40 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/01 13:33:02 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft.h"
# include <stdbool.h>

/* ---------------------------------- */
/* parse                              */
/* ---------------------------------- */

struct s_cmd
{
	void	*args;
	void	*redir;
};

t_lst	parse(const char *input);

/* ---------------------------------- */
/* prep                               */
/* ---------------------------------- */

//	status: redir result, command not found ...
struct s_exec
{
	char	**args;
	int		fd_in;
	int		fd_out;
	bool	status;
};

t_lst	prep(const t_lst *exelst_ref);

/* ---------------------------------- */
/* exec                               */
/* ---------------------------------- */

void	exec(t_lst exelst);

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

#endif // MAIN_H
