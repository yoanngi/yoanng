/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:05:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 10:06:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Take infos in Env
*/

static char		*ft_check_infos(char **env, char *find)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strstr(env[i], find))
			path = ft_strdup(env[i]);
		i++;
	}
	return (path);
}

/*
**	Allocation memory for struct and initialise datas
*/

t_struct		*ft_my_struct(char **env)
{
	t_struct	*data;
	char		*tmp;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	tmp = ft_check_infos(env, "PATH");
	data->path = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
	ft_strdel(&tmp);
	data->tab_path = ft_strsplit(data->path, ':');
	tmp = ft_check_infos(env, "PWD");
	data->pwd = ft_strsub(tmp, 4, ft_strlen(tmp) - 4);
	ft_strdel(&tmp);
	return (data);
}

/*
**	Delete struct ans datas
*/

void			ft_delete_struct(t_struct *data)
{
	ft_strdel(&data->path);
	ft_strdel(&data->pwd);
	ft_del_tab(data->tab_path);
	free(data);
	data = NULL;
}
