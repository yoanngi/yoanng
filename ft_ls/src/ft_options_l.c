/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:53:29 by yoginet     ###    #+. /#+    ###.fr     */
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
		if (ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			ret->user = ft_get_user(&fichierlu);
			ret->groupe = ft_get_groupe(&fichierlu);
			ret->date = ft_get_time(&fichierlu);
			ret->droit = ft_get_droit(&fichierlu);
			printf("Fichierlu = %s, user : %s, groupe : %s, droit = %s ,time = %s", fichierlu->d_name, ret->user, ret->groupe, ret->droit, ret->date);

			//ft_add_info(ret, &fichierlu);
			//(*ret)->user = &mystat.st_uid;
		}
		//*ret = ft_lstnew_ls();
		//*ret = (*ret)->next;
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
