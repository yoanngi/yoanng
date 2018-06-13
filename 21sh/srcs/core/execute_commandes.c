/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 13:52:29 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

// A Delete !
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
		printf("next\n");
		data->commandes = data->commandes->next;
	}
	data->commandes = test;
	printf("End debug ******************************************\n\n");
}

int				ft_process(t_struct *data)
{
	pid_t	father;
	int		exec;

	father = fork();
	exec = -1;
	if (father < 0)
	{
		ft_error_fork(father);
		exit(EXIT_FAILURE);
	}
	else if (father == 0)
	{
		exec = execve(data->commandes->rep, data->commandes->tab_cmd,
				data->commandes->env);
		if (exec == -1)
			kill(father, 0);
		return (exec);
	}
	else
		wait(&exec);
	return (father);
}

static int			exec_pipe_child(t_cmd *commandes, int pipe_fd[2], int *fd_in)
{
	int		exec;
	int		fd;

	exec = 0;
	if ((commandes->op_next == 2 || commandes->op_next == 3) && commandes->pathname != NULL)
	{
		if (commandes->op_next == 2)
			fd = open(commandes->pathname, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (commandes->op_next == 3)
			fd = open(commandes->pathname, O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd == -1)
			return (EXIT_FAILURE);
		dup2(*fd_in, 0);
		dup2(fd, 1);
		close(pipe_fd[0]);
		close(fd);
		exec = execve(commandes->rep, commandes->tab_cmd, commandes->env);
		if (exec == -1)
			return (EXIT_FAILURE);
	}
	else if (commandes->next != NULL)
	{
		dup2(*fd_in, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		exec = execve(commandes->rep, commandes->tab_cmd, commandes->env);
		if (exec == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int			exec_cmd_recur(t_struct *data)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		fd_in;
	int		status;
	int		ret;

	fd_in = 0;
	status = 0;
	while (data->commandes)
	{
		if (pipe(pipe_fd) == -1)
			return (EXIT_FAILURE);
		if ((pid = fork()) == -1)
			return (EXIT_FAILURE);
		if (pid == 0)
		{
			ret = exec_pipe_child(data->commandes, pipe_fd, &fd_in);
			if (ret == 1)
			{
				kill(pid, 0);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
			data->commandes = data->commandes->next;
		}
	}
	data->ret_func = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}

int			execute_commandes(t_struct *data)
{
	int		ret;
	int		status;
	pid_t	pid_p;

	// A delete
	debug(data);
	// *******
	ret = 0;
	if (len_list(data->commandes) == 1)
		return (ft_process(data));
	if ((pid_p = fork()) == -1)
		ft_putstr_fd("Error Fork Father\n", 2);
	else if (pid_p == 0)
		ret = exec_cmd_recur(data);
	else
		waitpid(pid_p, &status, 0);
	ret == 1 ? ft_putstr_fd("Un erreur c'est produite\n", 2) : 0;
	return (EXIT_SUCCESS);
}
