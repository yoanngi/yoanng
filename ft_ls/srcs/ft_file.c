/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 16:02:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Le fichier existe ?
*/
int				ft_file_exist(char *file_ornot)
{
	DIR		*dir;

	if ((dir = opendir(file_ornot)) != NULL)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}
/*
**	Acces au fichier ou non
*/
int				ft_access_or_not(char **path)
{
	t_stat	buf;
	
	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
	}
	if (buf.st_mode & EACCES)
		return (1);
	return (0);
}

t_lst			*ft_return_access_denied(t_dir **fichierlu, char *path)
{
	t_lst	*rep;

	rep = ft_lstnew_ls();
	rep->path = ft_strdup(path);
	rep->name = ft_strdup((*fichierlu)->d_name);
	return (rep);	
}