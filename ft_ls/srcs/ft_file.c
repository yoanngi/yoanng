/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 16:36:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Directory exit or not
*/

int				ft_access_or_not(char **path)
{
	DIR		*dir;

	if ((dir = opendir(*path)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}

/*
**	File exist or not
*/

int				ft_is_file(char **path)
{
	t_stat	buf;

	if (lstat(*path, &buf) == -1)
		return (0);
	return (1);
}

/*
**	Return chain list Directory
*/

t_rep			*ft_dir_valid(int i, int nb, char **params)
{
	t_rep	*lst;
	t_rep	*cpy;

	lst = ft_lstnew_argv();
	cpy = lst;
	ft_range_tab(params, nb, i);
	while (i != nb)
	{
		if (ft_access_or_not(&params[i]) == 1)
		{
			if (lst->name != NULL)
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

/*
**	Return chain list files
*/

t_rep			*ft_file_valid(int i, int nb, char **params)
{
	t_rep	*lst;
	t_rep	*cpy;

	lst = ft_lstnew_argv();
	cpy = lst;
	ft_range_tab(params, nb, i);
	while (i != nb)
	{
		if (ft_is_file(&params[i]) == 1)
		{
			if (lst->name != NULL)
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

void			ft_error_argv(int i, int nb, char **params)
{
	ft_range_tab(params, nb, i);
	while (i != nb)
	{
		if (params[i][0] != '\0')
			basic_error(params[i]);
		i++;
	}
}
