/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:26:45 by yoginet     ###    #+. /#+    ###.fr     */
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

	ret = ft_lstnew_ls();
	cpy = ret;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		ret->name = ft_strdup(fichierlu->d_name);
		ret->user = ft_get_user(&fichierlu);
		ret->groupe = ft_get_groupe(&fichierlu);
		ret->date = ft_get_time(&fichierlu);
		ret->time = ft_return_time(ret->date);
		ret->month = ft_return_month(ret->date);
		ret->day = ft_return_day(ret->date);
		ret->droit = ft_get_droit(&fichierlu);
		ret->size = ft_get_size(&fichierlu);
		ret->link = ft_get_link(&fichierlu);
		ret->otherfile = NULL;
		ret->next = ft_lstnew_ls();
		ret = ret->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_l(s_struct *data)
{
	t_lst *rep;

	printf("ft_ls_l\n");
	rep = ft_recupere_info(data);
	return (rep);
}
