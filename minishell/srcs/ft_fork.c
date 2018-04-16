/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:04:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 15:53:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Verifie Directory behind fork
*/

static int		good_path(char *target, char *cmd)
{
	DIR				*dir;
	struct dirent	*fl;
	
	dir = opendir(target);
	while ((fl = readdir(dir)) != NULL)
	{
		if (ft_strcmp(cmd, fl->d_name) == 0)
			return (1);
	}
	closedir(dir);	
	return (0);
}

/*
**	Create process
*/

int				ft_process(char *rep, char **cmd)
{
	pid_t	father;
	int		exec;

	if (good_path(rep, cmd[0]) == 1)
		father = fork();
	else
		return (-1);
	exec = -1;
	if (father < 0)
	{
		basic_error("Erreur de creation de processus");
		exit(0);
	}
	else if (father == 0)
	{
		exec = execve(rep, cmd, NULL);
		return (exec);
	}
	else
	{
		waitpid(father, &exec, 0);
		kill(father, SIGQUIT);
	}
	return (father);
}
