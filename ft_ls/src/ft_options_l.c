/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 16:31:50 by yoginet     ###    #+. /#+    ###.fr     */
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

	printf("ft_recupere_info\n");
	ret = ft_lstnew_ls();
	cpy = ret;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("TOUR DE BOUCLE   ");
		printf("Fichier lu = %s\n", fichierlu->d_name);
		ret->name = ft_strdup(fichierlu->d_name);
		printf("name = %s\n", ret->name);
		ret->user = ft_get_user(&fichierlu);
		printf("user = %s\n", ret->user);
		ret->groupe = ft_get_groupe(&fichierlu);
		printf("group = %s\n", ret->groupe);
		ret->date = ft_get_time(&fichierlu);
		printf("date = %s", ret->date);
		ret->droit = ft_get_droit(&fichierlu);
		printf("droit = %s\n", ret->droit);
		ret->size = ft_get_size(&fichierlu);
		printf("size = %d\n", ret->size);
		ret->link = ft_get_link(&fichierlu);
		printf("link = %d\n", ret->link);
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
