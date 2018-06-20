/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_search_path.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 11:18:28 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 14:39:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void			ft_reload_path(t_struct **data)
{
	ft_strdel(&(*data)->path);
	(*data)->tab_path = ft_del_tab((*data)->tab_path);
	ft_load_path(data);
}

static int			ft_search_in_dir(char *rep, char *str)
{
	DIR				*dir;
	struct dirent	*fl;

	if ((dir = opendir(rep)) == NULL)
		return (1);
	while ((fl = readdir(dir)))
	{
		if (ft_strcmp(fl->d_name, str) == 0)
			return (0);
	}
	closedir(dir);
	return (1);
}

char				*ft_search_path(char *str, t_struct *data)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	ft_reload_path(&data);
	while(data->tab_path[i])
	{
		if (ft_search_in_dir(data->tab_path[i], str) == 0)
		{
			tmp = ft_strdup(data->tab_path[i]);
			tmp2 = ft_strjoin(tmp, "/");
			ft_strdel(&tmp);
			tmp = ft_strjoin(tmp2, str);
			ft_strdel(&tmp2);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
