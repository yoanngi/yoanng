/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   execute_commandes.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/11 09:36:12 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 11:43:12 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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

int			exec_pipe_suite(t_struct *data)
{
	pid_t	father;
	int		pipefd[2];
	int		exec;

	/* DEBUG */
	printf("Debug :\n");
	printf("data->commandes->rep = %s\n", data->commandes->rep);
	printf("data->commandes->tab_cmd[0] = %s\n", data->commandes->tab_cmd[0]);
	printf("data->commandes->tab_cmd[1] = %s\n", data->commandes->tab_cmd[1]);
	printf("data->commandes->next->rep = %s\n", data->commandes->next->rep);
	printf("data->commandes->next->tab_cmd_[0] = %s\n", data->commandes->next->tab_cmd[0]);
	printf("data->commandes->next->tab_cmd_[1] = %s\n", data->commandes->next->tab_cmd[1]);
	/* END DEBUD */
	
	exec = -1;
	if (pipe(pipefd) == -1 || (father = fork()) < 0)
	{
		ft_putstr_fd("Une erreur c'est produite (fork ou pipe)\n", 2);
		return (-1);
	}
	if (father == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		exec = execve(data->commandes->next->rep, data->commandes->next->tab_cmd,
	data->commandes->next->env);
		if (exec == -1)
			kill(father, 0);
		return (exec);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		exec = execve(data->commandes->rep, data->commandes->tab_cmd,
	data->commandes->env);
		if (exec == -1)
			kill(father, 0);
		return (exec);
	}
	return (exec);
}

int			exec_pipe(t_struct *data)
{
	int		ret;

	ret = 0;
	while (data->commandes->next)
	{
		ret = exec_pipe_suite(data);
		data->commandes = data->commandes->next;
	}
	return (ret);
}

int			execute_commandes(t_struct *data)
{
	int		ret;

	ret = 0;
	if (data->pipe == 1 || data->redirection == 1)
		ret = exec_pipe(data);
	else
		ret = ft_process(data);
	return (ret);
}
