/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/08 10:51:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			exec_pipe_child(t_struct *mystruct, t_cmd *lst, int pipe_fd[2],
    int *fd_in)
{
	int		builtins;

	if ((builtins = execute_builtins(mystruct, lst, pipe_fd, fd_in)) != -1)
		return (builtins);
    // code de retour a check
	if (lst->op_next == 2 || lst->op_next == 3)
        return (fork_redirection(lst, pipe_fd, fd_in));
	if (lst->op_next == 1)
	{
		dup2(*fd_in, 0) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
		dup2(pipe_fd[1], 1) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
		close(pipe_fd[0]) == -1 ? ft_putstr_fd("error close 1\n", 2) : 0;
		return (execve(lst->rep, lst->tab_cmd, lst->env));
	}
	dup2(*fd_in, 0) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
	close(pipe_fd[1]) == -1 ? ft_putstr_fd("error close 2\n", 2) : 0;
	close(pipe_fd[0]) == -1 ? ft_putstr_fd("error close 3\n", 2) : 0;
	return (execve(lst->rep, lst->tab_cmd, lst->env));
}

/*
**	Bla
*/

static int			exec_cmd_recur(t_struct *mystruct, t_cmd *data)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		fd_in;
	int		status;

	fd_in = 0;
	while (data)
	{
		if (pipe(pipe_fd) == -1)
			exit(EXIT_FAILURE);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			if (exec_pipe_child(mystruct, data, pipe_fd, &fd_in) == -1)
				kill(pid, 0);
		}
		else
		{
			data->pid = pid;
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
		}
		data = data->next;
	}
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

/*
**	On envoie la liste chainee a exec_cmd_recur
*/

int					execute_commandes(t_struct *mystruct, t_cmd *data)
{
	int		ret;
	t_cmd	*start;

	start = NULL;
	ret = 0;
	if (!data)
		return (-1);
	if (len_list(data) == 1 && (data->op_next != 2 && data->op_next != 3))
	{
		if ((ret = execute_builtins_light(mystruct, data)) == -2)
			return (ft_process(data));
		else
			return (ret);
	}
	start = data;
	ret = exec_cmd_recur(mystruct, data);
	ft_kill_process(start);
	return (ret);
}
