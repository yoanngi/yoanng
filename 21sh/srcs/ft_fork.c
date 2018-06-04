/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:04:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 13:53:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Create process and execute commande
**	Repertoire : rep
**	commande : cmd
**	Environement : env
*/

int				ft_process(char *rep, char **cmd, char **env)
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
		exec = execve(rep, cmd, env);
		if (exec == -1)
			kill(father, 0);
		return (exec);
	}
	else
		wait(&exec);
	return (father);
}

/*
**	Ft_processe avec pipe
**
*/

int				ft_process_pipe(char *rep, char **cmd, char **env)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);

}
