/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 17:24:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	debug(t_struct *data)
{
	/* DEBUG */
	printf("Debug : (%s)\n", __func__);
	printf("data->commandes->rep = %s\n", data->commandes->rep);
	printf("data->commandes->tab_cmd[0] = %s\n", data->commandes->tab_cmd[0]);
	printf("data->commandes->tab_cmd[1] = %s\n", data->commandes->tab_cmd[1]);
	printf("data->commandes->next->rep = %s\n", data->commandes->next->rep);
	printf("data->commandes->next->tab_cmd_[0] = %s\n", data->commandes->next->tab_cmd[0]);
	printf("data->commandes->next->tab_cmd_[1] = %s\n", data->commandes->next->tab_cmd[1]);
	printf("data->commandes->next->next->rep = %s\n", data->commandes->next->next->rep);
	printf("data->commandes->next->next->tab_cmd_[0] = %s\n", data->commandes->next->next->tab_cmd[0]);
	printf("data->commandes->next->next->tab_cmd_[1] = %s\n", data->commandes->next->next->tab_cmd[1]);
	/* END DEBUG */
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

int			exec_cmd(t_struct *data)
{
	int		ret;
	int		pipe_fd[2];
	pid_t	pid;

	ret = 0;
	debug(data);
	if (pipe(pipe_fd) == -1 || (pid = fork()) == -1)
	{
		ft_putstr_fd("Une erreur c'est produite (fork ou pipe)\n", 2);
		return (-1);
	}
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		exec = execve(data->commandes->next->rep, data->commandes->next->tab_cmd,
				data->commandes->next->env);
	}
	return (ret);
}

int			execute_commandes(t_struct *data)
{
	t_cmd	*start;
	int		ret;
	int		pipe_fd[2];
	pid_t	pid;

	start = data->commandes;
	ret = 0;
	if (pipe(pipe_fd) == -1)
		ft_putstr_fd("Une Erreur c'est produite\n", 2);
	if ((pid = fork()) == -1)
		ft_putstr_fd("Une Erreur c'est produite\n", 2);
	while (start)
	{
		if (pid == 0)
			ret = exec_cmd(start);
		else
			ret = exec_cmd_son(start);
		start = start->next;
	}
	return (ret);
}
