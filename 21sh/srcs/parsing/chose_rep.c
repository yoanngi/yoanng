/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   chose_rep.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/26 13:40:50 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 15:46:54 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				ft_search_opnext(char *str, int i)
{
	int		len;

	len = ft_strlen(str);
	if (i < len)
	{
		if (str[i] == '<' && str[i + 1] == '<')
			return (5);
		if (str[i] == '>' && str[i + 1] == '>')
			return (3);
		if (str[i] == '>' && str[i + 1] == '&')
			return (9);
	}
	if (str[i] == '|')
		return (1);
	else if (str[i] == '>')
		return (2);
	else if (str[i] == '<')
		return (4);
	else if (str[i] == '&')
		return (4);
	return (0);
}

static int		read_path(char *rep, char *name)
{
	DIR				*dir;
	struct dirent	*fl;
	int				ret;
	
	ret = 0;
	if ((dir = opendir(rep)) == NULL)
		return (1);
	while ((fl = readdir(dir)) != NULL)
	{
		if (ft_strcmp(fl->d_name, name) == 0)
			ret = 1;
	}
	if (closedir(dir) == -1)
		return (1);
	return (ret);
}

static int		chose_rep_provisoire(t_cmd **new)
{
	char	*tmp;
	char	**env_p;
	int		i;

	tmp = NULL;
	env_p = NULL;
	i = 0;
	tmp = ft_check_infos((*new)->env, "PATH=");
	// **************************************
	ft_printf("tmp = %s\n", tmp);
	env_p = ft_strsplit(tmp, ':');
	while (env_p[i])
	{
		if (read_path(env_p[i], (*new)->tab_cmd[0]) == 0)
		{
			(*new)->rep = ft_strdup(env_p[i]);
			ft_strdel(&tmp);
			return (0);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

int				chose_rep(t_struct *data, t_cmd **new, int provisoire)
{
	if (provisoire == 1)
	{
		chose_rep_provisoire(new);
		return (0);
	}
	if (ft_strstr((*new)->tab_cmd[0], "./") != NULL)
		(*new)->rep = ft_strdup((*new)->tab_cmd[0]);
	else
	{
		(*new)->rep = ft_search_path((*new)->tab_cmd[0], data);
	}
	return (0);
}