/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 16:42:46 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst		*ft_recupere_info(s_struct *data, t_lst *ret)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*cpy;

	cpy = ret;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		ret->name = ft_strdup(fichierlu->d_name);
		ret->user = ft_get_user(&fichierlu);
		ret->groupe = ft_get_groupe(&fichierlu);
		ret->date = ft_get_time(&fichierlu);
		ret->droit = ft_get_droit(&fichierlu);
		ret->size = ft_get_size(&fichierlu);
		ret->link = ft_get_link(&fichierlu);
		ret = ft_lstnew_ls();
		ret = ret->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_l(s_struct *data)
{
	t_lst	*ret;
	t_lst	*cpy;

	if (data->liste != NULL)
	{
		ret = data->liste;
		return (ret);
	}
	else
		ret = ft_lstnew_ls();
	cpy = ft_recupere_info(data, ret);
	free(ret);
	return (cpy);
}
