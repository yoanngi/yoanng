/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_cd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:21:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 10:08:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Sycronise path in env
*/

static void		ft_insert_in_env_suite(t_struct *data)
{
	int		i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PWD=", 4) == 0)
		{
			ft_strdel(&data->env[i]);
			data->env[i] = ft_strjoin("PWD=", data->pwd);
		}
		if (ft_strncmp(data->env[i], "OLDPWD=", 7) == 0)
		{
			ft_strdel(&data->env[i]);
			data->env[i] = ft_strjoin("OLDPWD=", data->oldpwd);
		}
		i++;
	}
}

static void		ft_insert_in_env(t_struct *data)
{
	char	*buf;

	if (data->env == NULL)
		return ;
	buf = ft_strnew(512);
	getcwd(buf, 512);
	ft_strdel(&data->oldpwd);
	data->oldpwd = ft_strdup(data->pwd);
	ft_strdel(&data->pwd);
	data->pwd = ft_strdup(buf);
	ft_strdel(&buf);
	ft_insert_in_env_suite(data);
}

/*
**	Special func for ~
*/

static char		*ft_tild(char *target, t_struct *data)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strlen(target) > 1)
		tmp = ft_strsub(target, 1, ft_strlen(target) - 1);
	else
		tmp = ft_strdup("/");
	ft_strdel(&target);
	target = ft_strdup(data->home);
	tmp2 = ft_strjoin(target, tmp);
	ft_strdel(&target);
	target = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (target);
}

/*
**	Check target for change directory
*/

static char		*func_return_target(char *line, t_struct *data)
{
	char	*target;
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
		i++;
	if (i == 1)
		target = ft_strdup(data->home);
	else if (ft_strlen(line) == 4 && line[3] == '-')
		target = ft_strdup(data->oldpwd);
	else if (ft_strlen(line) == 5 && line[3] == '~' && line[4] == '-')
		target = ft_strdup(data->home);
	else
		target = ft_strdup(tab[i - 1]);
	if (ft_strstr(target, "~") != NULL)
		target = ft_tild(target, data);
	ft_del_tab(tab);
	return (target);
}

/*
**	Change directory
*/

int				func_cd(char **line, t_struct *data)
{
	int		i;
	int		ret;
	char	*tmp;

	i = 0;
	tmp = func_return_target(*line, data);
	if (ft_access(tmp) == -1)
	{
		ft_strdel(&tmp);
		return (1);
	}
	if ((ret = chdir(tmp)) == -1)
	{
		ft_putstr_fd("cd: no such file of directory: ", 2);
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_insert_in_env(data);
	ft_strdel(&tmp);
	return (1);
}
