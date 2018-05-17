/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   various_func.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 10:06:21 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 14:25:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Delete tab and return NULL
*/

char		*ft_del_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

/*
**	Add commande in end of path
*/

static char	*ft_cmp_path(char *str, char **add, t_struct *data)
{
	int	i;
	char	*tmp;
	char	*tmp2;

	i = ft_strlen(*add);
	tmp = ft_strdup(*add);
	tmp2 = NULL;
	while (i > 0 && tmp[i] != '/')
		i--;
	ft_strdel(&tmp);
	tmp = ft_strsub(*add, 0, i);
	if (ft_strcmp(tmp, str) == 0)
	{
		ft_strdel(&tmp);
		tmp = ft_strdup(*add);
		ft_strdel(add);
		*add = ft_strsub(tmp, i + 1, (ft_strlen(tmp) - i - 1));
		return (tmp);
	}
	else
	{
		ft_strdel(&tmp);
		tmp = ft_strjoin(data->pwd, "/");
		tmp2 = ft_strjoin(tmp, *add);
		ft_strdel(&tmp);
	}
	printf("tmp2 = %s\n", tmp2);
	return (tmp2);
}

char		*ft_add_line(char *str, char **add, t_struct *data)
{
	char	*tmp;
	char	*new;

	tmp = NULL;
	new = NULL;
	if (ft_strstr(*add, "/") != NULL)
	{
		new = ft_cmp_path(str, add, data);
		if (new == NULL)
			new = ft_strjoin(str, *add);
		return (new);
	}
	tmp = ft_strjoin(str, "/");
	new = ft_strjoin(tmp, *add);
	ft_strdel(&tmp);
	return (new);
}

/*
**	Return len tab
*/

int			ft_len_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

/*
**	Directory exist of not
*/

int			ft_dir_exist(char *path)
{
	DIR		*dir;

	if (!(dir = opendir(path)))
		return (0);
	closedir(dir);
	return (1);
}
