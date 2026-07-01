/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseobk <minseobk@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:32:40 by minseobk          #+#    #+#             */
/*   Updated: 2026/07/01 12:41:14 by minseobk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft.h"
# include <stdbool.h>

/* ---------------------------------- */
/* prom                               */
/* ---------------------------------- */

char	*prom(void);
// 스트링 반환
// -> 니가 알아서 exit()
/**

	prom():
		signal(니가필요한거 하고싶은거 해)
		while (1)
			input = readline();
			if (err?)
				exit(1);
			break ;
		add_history();
		return (input);
 */

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
