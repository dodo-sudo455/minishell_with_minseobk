# /src/exec

```c
enum e_redirtype
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_HDOC,
	REDIR_APPEND
};

struct s_redir
{
	t_redirtype	t;
	char		*s;
};

struct s_cmd
{
	t_lst	arglst;
	t_lst	redlst;
};

exec_run(ctx, cmdlst):
	
	fd := int{0, 1, 0, 1}
	
	for each node in cmdlst:
		cmd := node.data
		pfd := int[2]{-1, -1}
		
		if node.next:
			pipe(pfd)
		else:
			fd[1], fd[2] = 1, 2
		fd[0], fd[1] = fd[2], fd[3]
	
		ok := handle_redir(ctx, cmd.redlst, fd)
		if !ok:
			abort(cmd)
		else:
			run(cmd, fd)



handle_redir(ctx, redlst, fd[2])

	for each redir in redlst:

		if redir.type == REDIR_IN {
			tmp := open(redir.str)
			dup2(tmp, fd[0])
		}
		else if redir.type == REDIR_OUT {
			tmp := open(redir.str)
			dup2(tmp, fd[1])
		}
		else if redir.type == REDIR_HDOC {
			tmp := open(redir.str)
			dup2(tmp, fd[0])
		}
		else if redir.type == REDIR_APP {
			tmp := open(redir.str)
			dup2(tmp, fd[1])
		}
		else
			panic()

```
