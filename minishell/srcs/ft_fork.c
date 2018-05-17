/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:04:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 13:46:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Verifie Directory behind fork
*/

// A mettre au propre (gestion d'un path diffent de l'env)
// ./a.out , ./minishell etc...

static int		good_path_suite(char *cmd, char *name, int ret, char *target)
{
	if (ft_strcmp(cmd, name) == 0)
	{
		printf("name ok\n");
		if (!(access(target, X_OK) & EACCES))
			ret = 1;
		else
		{
			basic_error("permission denied: ", cmd);
			ret = 0;
		}
	}
	if (ft_strstr(cmd, "./") != NULL)
	{
		if (ft_strcmp(cmd + 2, name) == 0)
			ret = 1;
	}
	return (ret);
}

int				good_path(char *target, char *cmd)
{
	DIR		*dir;
	struct dirent	*fl;
	char		*tmp;
	int		ret;

	ret = -1;
	tmp = ft_strsub(target, 0, (ft_strlen(target) - ft_strlen(cmd)));
	if ((dir = opendir(tmp)) == NULL)
	{
		ft_strdel(&tmp);
		return (ret);
	}
	ft_strdel(&tmp);
	while (((fl = readdir(dir)) != NULL) && ret == -1)
		ret = good_path_suite(cmd, fl->d_name, ret, target);
	if ((closedir(dir)) == -1)
		return (ret);
	return (ret);
}

/*
**	Error Fork
*/

static void		error_fork(int father)
{
	char *tmp;

	tmp = ft_itoa(father);
	basic_error("Erreur de creation de processus", tmp);
	ft_strdel(&tmp);
}

/*
**	Create process
*/

int				ft_process(char *rep, char **cmd)
{
	pid_t	father;
	int		exec;
	int		good;

	if ((good = good_path(rep, cmd[0])) == 1)
		father = fork();
	else
		return (good);
	exec = -1;
	if (father < 0)
	{
		error_fork(father);
		exit(EXIT_FAILURE);
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
