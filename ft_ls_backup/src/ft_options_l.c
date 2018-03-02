/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 16:30:41 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_insert_infos(t_lst **ret, char *tmp)
{
	(*ret)->droit = ft_get_droit(&tmp);
	(*ret)->user = ft_get_user(&tmp);
	(*ret)->groupe = ft_get_groupe(&tmp);
	(*ret)->date = ft_get_time(&tmp);
	(*ret)->time = ft_return_time((*ret)->date);
	(*ret)->month = ft_return_month((*ret)->date);
	(*ret)->day = ft_return_day((*ret)->date);
	(*ret)->size = ft_get_size(&tmp);
	(*ret)->link = ft_get_link(&tmp);
	(*ret)->blocks = ft_get_blocks(&tmp);
	if ((*ret)->droit[0] == 'l')
		(*ret)->symbol = ft_get_new_path(&tmp);
	else
		(*ret)->symbol = NULL;
	(*ret)->otherfile = NULL;
}

static t_lst		*ft_recupere_info(s_struct *data, int indexfile, char *file)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*cpy;
	t_lst		*ret;
	char		*tmp;

	ret = ft_lstnew_ls();
	cpy = ret;
	file = ft_strdup(data->multifile[indexfile]);
	file = ft_strjoin(data->multifile[indexfile], "/");
	dir = opendir(file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		tmp = ft_strdup(file);
		tmp = ft_strjoin(tmp, fichierlu->d_name);
		ret->name = ft_strdup(fichierlu->d_name);
		ft_insert_infos(&ret, tmp);
		ft_strdel(&tmp);
		ret->next = ft_lstnew_ls();
		ret = ret->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_l(s_struct *data, int indexfile)
{
	t_lst	*rep;
	char	*tmp;

	tmp = NULL;
	if (data->liste == NULL)
	{
		rep = ft_recupere_info(data, indexfile, tmp);
		ft_strdel(&tmp);
		return (rep);
	}
	return (data->liste);
}