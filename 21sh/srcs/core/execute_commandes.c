/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 14:30:58 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

//********************************************************************* A Delete !
/*
static void	debug(t_struct *data)
{
	t_cmd	*test;

	test = data->commandes;
	printf("***(%s)***\n", __func__);
	while (data->commandes)
	{
		printf("data->commandes->rep = %s\n", data->commandes->rep);
		printf("data->commandes->pathname = %s\n", data->commandes->pathname);
		if (data->commandes->tab_cmd != NULL)
		{
			printf("data->commandes->tab_cmd[0] = %s\n", data->commandes->tab_cmd[0]);
			printf("data->commandes->tab_cmd[1] = %s\n", data->commandes->tab_cmd[1]);
			printf("data->commandes->tab_cmd[2] = %s\n", data->commandes->tab_cmd[2]);
		}
		printf("data->commandes->stdin_cmd = %d\n", data->commandes->stdin_cmd);
		printf("data->commandes->stdout_cmd = %d\n", data->commandes->stdout_cmd);
		printf("data->commandes->stderr_cmd = %d\n", data->commandes->stderr_cmd);
		printf("data->commandes->op_redir = %d\n", data->commandes->op_redir);
		printf("data->commandes->op_next = %d\n", data->commandes->op_next);
		printf("next\n");
		data->commandes = data->commandes->next;
	}
	data->commandes = test;
	printf("End debug ******************************************\n\n");
}
*/
//**************************************************************************

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
	int		exec;

	exec = 0;
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
		exec = execve(lst->rep, lst->tab_cmd, lst->env);
		if (exec == -1)
			exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int			exec_cmd_recur(t_struct *data)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		fd_in;
	int		status;

	fd_in = 0;
	while (data->commandes)
	{
		if (pipe(pipe_fd) == -1)
			exit(EXIT_FAILURE);
		if ((pid = fork()) == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			if (exec_pipe_child(data->commandes, pipe_fd, &fd_in) == 1)
			{
				kill(pid, 0);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			data->ret_func = WEXITSTATUS(status);
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
		}
		data->commandes = data->commandes->next;
	}
	return (EXIT_SUCCESS);
}

int			execute_commandes(t_struct *data)
{
	int		ret;
	int		status;
	pid_t	pid_p;

	ret = 0;
	if (len_list(data->commandes) == 1)
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
