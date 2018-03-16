/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 16:05:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Acces au fichier ou non
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
**	Retourne un maillon avec le nom et path du fichier dont on a pas l'access
*/

t_lst			*ft_return_access_denied(t_dir **fichierlu, char *path)
{
	t_lst	*rep;

	rep = ft_lstnew_ls();
	rep->path = ft_strdup(path);
	rep->name = ft_strdup((*fichierlu)->d_name);
	rep->otherfile = NULL;
	rep->next = NULL;
	return (rep);
}

/*
**	Le fichier est valide ?
*/

int				ft_is_file(char **path, t_struct *data)
{
	t_stat	buf;
	t_lst	*ret;

	ret = NULL;
	if (lstat(*path, &buf) == -1)
		return (0);
	data->invalid = 1;
	ret = ft_lstnew_ls();
	ret->name = ft_strdup(*path);
	ret->droit = ft_get_droit(buf);
	ret->user = ft_get_user(buf);
	ret->groupe = ft_get_groupe(buf);
	ret->date = ft_get_time(buf);
	ft_minmajorsize(buf, &ret);
	ret->link = ft_get_link(buf);
	ret->blocks = ft_get_blocks(buf);
	ret->access = ft_access_or_not(path);
	if (ret->droit[0] == 'l')
		ret->symbol = ft_get_new_path(path);
	else
		ret->symbol = NULL;
	if (data->lmin == 1)
		ft_ls_liste(&ret, 1);
	else
		ft_putendl(*path);
	ft_clean_list(&ret);
	return (1);
}
