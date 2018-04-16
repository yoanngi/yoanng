/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:05:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 11:55:15 by yoginet     ###    #+. /#+    ###.fr     */
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
**	Copy env in struct
*/
static char		**ft_copie_env(char **env)
{
	int		i;
	char	**cpy;
	
	i = 0;
	cpy = NULL;
	while (env[i])
		i++;
	if (!(cpy = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (env[i])
	{
		cpy[i] = ft_strdup(env[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
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
	tmp = ft_check_infos(env, "PATH=");
	data->path = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
	ft_strdel(&tmp);
	data->tab_path = ft_strsplit(data->path, ':');
	tmp = ft_check_infos(env, "PWD=");
	data->pwd = ft_strsub(tmp, 4, ft_strlen(tmp) - 4);
	ft_strdel(&tmp);
	tmp = ft_check_infos(env, "HOME=");
	data->home = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
	ft_strdel(&tmp);
	data->current_path = ft_strdup(data->pwd);
	data->env = ft_copie_env(env);
	return (data);
}

/*
**	Delete struct ans datas
*/

void			ft_delete_struct(t_struct *data)
{
	ft_strdel(&data->path);
	ft_strdel(&data->pwd);
	ft_strdel(&data->home);
	ft_strdel(&data->current_path);
	ft_del_tab(data->tab_path);
	ft_del_tab(data->env);
	free(data);
	data = NULL;
}
