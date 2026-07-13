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
	prev_read_fd := 0

	set_signal_parent()	// ignore
	
	for each node in cmdlst:
		cmd := node.data
		pipe_fd := int[2]{-1, -1}
		
		if node.next:
			pipe(pipe_fd)
	
		pid := fork()
		if pid == 0:

			set_signal_child()	// SIG_DFL

			if prev_read_fd:
				dup2(prev_read_fd, STDIN)
				close(prev_read_fd)
		
			if node.next:
				dup2(pipe_fd[READ], STDOUT)
				close(pipe_fd[WRITE])
				close(pipe_fd[READ])

			ok := handle_redir(ctx, cmd.redlst, fd)
			if !ok:
				exit(1)
		
			run(cmd)
			exit(0)
		
		if prev_read_fd:
			close(prev_read_fd)
		
		if node.next:
			prev_read_fd = pipe_fd[READ]
			close(pipe_fd[WRITE])
	
	status := wait_all()


handle_redir(redlst) bool:

	for each redir in redlst:

		if redir.type == REDIR_IN || redir.type == REDIR_HDOC {
			in := open(redir.str, O_RDONLY)
			if in < 0:
				return false
			dup2(in, STDIN)
			close(in)
		}

		else if redir.type == REDIR_OUT {
			out := open(redir.str, O_WRONLY | O_CREAT | O_TRUNC, 0644)
			if out < 0:
				return false
			dup2(out, STDOUT)
			close(out)
		}

		else if redir.type == REDIR_APP {
			out := open(redir.str, O_WRONLY | O_CREAT | O_APPEND, 0644)
			if out < 0:
				return false
			dup2(out, STDOUT)
			close(out)
		}

		return true

```
