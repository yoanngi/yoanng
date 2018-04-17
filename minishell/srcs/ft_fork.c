/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:04:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 14:31:20 by yoginet     ###    #+. /#+    ###.fr     */
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
	char			*tmp;
	
	tmp = ft_strsub(target, 0, (ft_strlen(target) - ft_strlen(cmd)));
	if (!(dir = opendir(tmp)))
	{
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd(" : Permission Denied\n", 2);
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
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
		if (exec == -1)
			kill(father, SIGQUIT);
		return (exec);
	}
	else
		wait(&exec);
	return (father);
}
