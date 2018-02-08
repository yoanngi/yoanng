/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:45:16 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst		*ft_recupere_info(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*cpy;
	t_lst		*ret;
	char		*tmp;

	ret = ft_lstnew_ls();
	cpy = ret;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		tmp = ft_strdup(fichierlu->d_name);
		ret->name = ft_strdup(fichierlu->d_name);
		ret->user = ft_get_user(&tmp);
		ret->groupe = ft_get_groupe(&tmp);
		ret->date = ft_get_time(&tmp);
		ret->time = ft_return_time(ret->date);
		ret->month = ft_return_month(ret->date);
		ret->day = ft_return_day(ret->date);
		ret->droit = ft_get_droit(&tmp);
		ret->size = ft_get_size(&tmp);
		ret->link = ft_get_link(&tmp);
		ret->next = ft_lstnew_ls();
		ft_strdel(&tmp);
		ret = ret->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_l(s_struct *data)
{
	t_lst	*rep;

	if (data->liste == NULL)
	{
		rep = ft_recupere_info(data);
		return (rep);
	}
	return (data->liste);
}
