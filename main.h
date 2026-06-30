#ifndef MAIN_H
# define MAIN_H
# include <stdbool.h>

typedef struct s_lst	t_lst;
struct s_lst
{
	void	*data;
	t_lst	*next;
};

/* ---------------------------------- */
/* prom                               */
/* ---------------------------------- */

char	*prom();
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
