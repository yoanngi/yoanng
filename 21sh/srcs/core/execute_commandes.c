/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 16:36:33 by yoginet     ###    #+. /#+    ###.fr     */
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
	if (execve(lst->rep, lst->tab_cmd, lst->env) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int			exec_pipe_child(t_cmd *lst, int pipe_fd[2], int *fd_in)
{
	if ((lst->op_redir == 2 || lst->op_redir == 3) && lst->pathname != NULL)
	{
		if (exec_redirection(lst, fd_in, pipe_fd) == 1)
			exit(EXIT_FAILURE);
	}
	if (lst->op_next == 1)
	{
		dup2(*fd_in, 0) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
		dup2(pipe_fd[1], 1) == -1 ? ft_putstr_fd("error dup2\n", 2) : 0;
		close(pipe_fd[0]) == -1 ? ft_putstr_fd("error close\n", 2) : 0;
		if (execve(lst->rep, lst->tab_cmd, lst->env) == -1)
			exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int			exec_cmd_recur(t_cmd *data)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		fd_in;
	int		status;

	fd_in = 0;
	while (data)
	{
		if ((pipe(pipe_fd) == -1) && ((pid = fork()) == -1))
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			if (exec_pipe_child(data, pipe_fd, &fd_in) == 1)
			{
				kill(pid, 0);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
		}
		data = data->next;
	}
	return (WEXITSTATUS(status));
	//return (EXIT_SUCCESS);
}

static void		print_debug(t_cmd **data)
{
	t_cmd	*start;

	start = *data;
	while (start)
	{
		printf("[++++++++++++++++++++++++++++++++++]\n");
		printf("rep = %s\n", start->rep);
		printf("tab[0] = %s\n", start->tab_cmd[0]);
		printf("tab[1] = %s\n", start->tab_cmd[1]);
		printf("[----------------------------------]\n");
		start = start->next;
	}
}

int			execute_commandes(t_cmd *data)
{
	int		ret;
	int		status;
	pid_t	pid_p;

	ret = 0;
	print_debug(&data);
	if (len_list(data) == 1)
		return (ft_process(data));
	if ((pid_p = fork()) == -1)
		return (EXIT_FAILURE);
	else if (pid_p == 0)
	{
		if (exec_cmd_recur(data) == 1)
			exit(EXIT_FAILURE);
	}
	else
		waitpid(pid_p, &status, 0);
	ret == 1 ? ft_putstr_fd("Error execution, please try again !\n", 2) : 0;
	return (EXIT_SUCCESS);
}
