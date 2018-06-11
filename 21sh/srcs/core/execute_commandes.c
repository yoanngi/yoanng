/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 20:33:26 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	debug(t_struct *data)
{
	t_cmd	*test;

	test = data->commandes;
	printf("(%s)\n", __func__);
	while (data->commandes)
	{
		printf("data->commandes->rep = %s\n", data->commandes->rep);
		printf("data->commandes->tab_cmd[0] = %s\n", data->commandes->tab_cmd[0]);
		printf("data->commandes->tab_cmd[1] = %s\n", data->commandes->tab_cmd[1]);
		printf("next\n");
		data->commandes = data->commandes->next;
	}
	data->commandes = test;
	printf("End debug ******************************************\n\n");
}
/*
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
*/

static int			exec_cmd_father(t_cmd *commandes, int pipe_fd[2])
{
	int		exec;

	exec = 0;
	if (commandes->stdin_cmd == 1)
		close(pipe_fd[1]);
	else
		close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	exec = execve(commandes->rep, commandes->tab_cmd, commandes->env);
	ft_putstr_fd("Failled (father)\n", 2);
	return (exec);
}

static int			exec_cmd_child(t_cmd *commandes, int pipe_fd[2])
{
	int		exec;

	exec = 0;
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	if (commandes->stdout_cmd == 1)
		close(pipe_fd[1]);
	else
		close(pipe_fd[0]);
	exec = execve(commandes->rep, commandes->tab_cmd, commandes->env);
	ft_putstr_fd("Failled (child)\n", 2);
	return (exec);
}

static int			exec_cmd_recur(t_cmd *start)
{
	int		ret;
	pid_t	pid;
	int		pipe_fd[3];

	ret = 0;
	printf("%s\n", __func__);
	if (pipe(pipe_fd) == -1)
		ft_putstr_fd("Une Erreur c'est produite (pipe)\n", 2);
	if ((pid = fork()) == -1)
		ft_putstr_fd("Une Erreur c'est produite (fork)\n", 2);
	if (pid == 0)
	{
		ret = exec_cmd_child(start->next, pipe_fd);
		exec_cmd_recur(start->next);
	}
	ret = exec_cmd_father(start, pipe_fd);
	return (ret);
}

int			execute_commandes(t_struct *data)
{
	t_cmd	*start;
	int		ret;
	pid_t	pid_p;

	debug(data);
	start = data->commandes;
	ret = 0;
	if ((pid_p = fork()) == 0)
		ret = exec_cmd_recur(start);
	else
		wait(&pid_p);
	return (ret);
}

