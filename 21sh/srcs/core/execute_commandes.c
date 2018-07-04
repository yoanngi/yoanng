/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 16:42:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			exec_redirection(t_cmd *lst, int *fd_in, int pipe_fd[2])
{
	int		fd;

	fd = 0;
	if (lst->op_redir == 2)
		fd = open(lst->pathname, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (lst->op_redir == 3)
		fd = open(lst->pathname, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(*fd_in, 0) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
	dup2(fd, 1) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
	close(pipe_fd[0]) == -1 ? ft_putstr_fd("error close\n", 2) : 0;
	close(fd) == -1 ? ft_putstr_fd("error close\n", 2) : 0;
	return (execve(lst->rep, lst->tab_cmd, lst->env));
}

static int			exec_pipe_child(t_struct *mystruct, t_cmd *lst, int pipe_fd[2], int *fd_in)
{
	int		builtins;

	if ((builtins = execute_builtins(mystruct, lst, pipe_fd, fd_in)) != -1)
		return (builtins);
	if ((lst->op_redir == 2 || lst->op_redir == 3) && lst->pathname != NULL)
		return (exec_redirection(lst, fd_in, pipe_fd));
	if (lst->op_next == 1)
	{
		dup2(*fd_in, 0) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
		dup2(pipe_fd[1], 1) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
		close(pipe_fd[0]) == -1 ? ft_putstr_fd("error close\n", 2) : 0;
		return (execve(lst->rep, lst->tab_cmd, lst->env));
	}
	dup2(*fd_in, 0) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
	close(pipe_fd[1]) == -1 ? ft_putstr_fd("error close\n", 2) : 0;
	close(pipe_fd[0]) == -1 ? ft_putstr_fd("error close\n", 2) : 0;
	return (execve(lst->rep, lst->tab_cmd, lst->env));
}

/*
**	Wait a verifier
**	bon wait par rapport au nombre de fork ?
**	A Normer
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
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
		}
		data = data->next;
	}
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

// ***************************************************** A delete
static void			print_debug(t_cmd **data)
{
	t_cmd	*start;

	start = *data;
	printf("[++++++++++++++++++++++++++++++++++]\n");
	while (start)
	{
		printf("rep = %s\n", start->rep);
		printf("pathname = %s\n", start->pathname);
		printf("tab[0] = %s\n", start->tab_cmd[0]);
		printf("tab[1] = %s\n", start->tab_cmd[1]);
		printf("op_next = %d\n", start->op_next);
		printf("op_redir = %d\n", start->op_redir);
		start = start->next;
	}
	printf("[----------------------------------]\n\n");
}

/*
**  On fork pour maintenir l'acces au shell
**	On envoie la liste chainee a exec_cmd_recur
*/

int					execute_commandes(t_struct *mystruct, t_cmd *data)
{
	int		status;
	pid_t	pid_p;
	int		ret;

	// A DELETE **********************************************
	print_debug(&data);
	// *******************************************************
	ret = 0;
	if (!data)
		return (-1);
	if (len_list(data) == 1)
	{
		if ((ret = execute_builtins_light(mystruct, data)) == -2)
			return (ft_process(data));
		else
			return (ret);
	}
	if ((pid_p = fork()) == -1)
		return (-1);
	else if (pid_p == 0)
		ret = exec_cmd_recur(mystruct, data);
	else
		waitpid(pid_p, &status, 0);
	return (ret);
}
