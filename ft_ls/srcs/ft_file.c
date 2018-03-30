/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 11:55:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Directory exit or not
*/

int					ft_access_or_not(char **path)
{
	DIR		*dir;
	char	*tmp;

	tmp = ft_strdup(*path);
	if (tmp[0] == '\0')
	{
		ft_strdel(&tmp);
		return (0);
	}
	if ((dir = opendir(tmp)) == NULL)
	{
		ft_strdel(&tmp);
		return (0);
	}
	closedir(dir);
	ft_strdel(&tmp);
	return (1);
}

/*
**	File exist or not
*/

int					ft_is_file(char **path)
{
	t_stat	buf;

	if (*path[0] == '\0')
		return (0);
	if (lstat(*path, &buf) == -1)
		return (0);
	return (1);
}

/*
**	Return chain list Directory
*/

t_rep				*ft_dir_valid(int i, int nb, char **params)
{
	t_rep	*lst;
	t_rep	*cpy;

	lst = NULL;
	cpy = NULL;
	while (i != nb)
	{
		if (ft_access_or_not_start(&params[i]) == 1)
		{
			if (!lst)
			{
				lst = ft_lstnew_argv();
				cpy = lst;
			}
			else
			{
				lst->next = ft_lstnew_argv();
				lst = lst->next;
			}
			ft_adressage(&lst, params[i]);
			ft_bzero(params[i], ft_strlen(params[i]));
		}
		i++;
	}
	return (cpy);
}

/*
**	Return chain list files
*/

t_rep				*ft_file_valid(int i, int nb, char **params)
{
	t_rep	*lst;
	t_rep	*cpy;

	lst = NULL;
	cpy = NULL;
	while (i != nb)
	{
		if (ft_is_file(&params[i]) == 1)
		{
			if (!lst)
			{
				lst = ft_lstnew_argv();
				cpy = lst;
			}
			else
			{
				lst->next = ft_lstnew_argv();
				lst = lst->next;
			}
			lst->name = ft_strdup(params[i]);
			ft_bzero(params[i], ft_strlen(params[i]));
		}
		i++;
	}
	return (cpy);
}
