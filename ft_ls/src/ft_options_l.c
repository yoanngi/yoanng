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

static t_lst		*ft_recupere_info(s_struct *data, int indexfile)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*cpy;
	t_lst		*ret;
	char		*tmp;

	ret = ft_lstnew_ls();
	cpy = ret;
	data->multifile[indexfile] = ft_strdup(".");
	printf("OUverture du fichier\n");
//	dir = opendir(data->multifile[indexfile]);
	dir = opendir("src");
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
	printf("end fonction\n");
	return (cpy);
}

t_lst				*ft_ls_l(s_struct *data, int indexfile)
{
	t_lst	*rep;

	printf("fichier option l\n");
	printf("data->multifile[%d] = %s\n", indexfile, data->multifile[indexfile]);
	if (data->liste == NULL)
	{
		rep = ft_recupere_info(data, indexfile);
		return (rep);
	}
	printf("end fichier option l\n");
	return (data->liste);
}
