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

void			ft_get_droit_data(s_struct **data)
{
	struct passwd 	*user;
	struct group 	*groupe;
	t_stat			buf;

	if (lstat("/Users/yoginet", &buf) == -1)
		basic_error("/Users/yoginet");
	user = getpwuid(buf.st_uid);
	groupe = getgrgid(buf.st_gid);
	(*data)->user_data = ft_strdup(user->pw_name);
	(*data)->groupe_data = ft_strdup(groupe->gr_name);
}

int				ft_access_or_not(s_struct *data, t_lst *liste)
{
	int i;

	i = 0;
	printf("liste->droit = %s\n", liste->droit);
	printf("data->user_data = %s\n", data->user_data);
	printf("data->groupe_data = %s\n", data->groupe_data);
	printf("liste->user = %s\n", liste->user);
	printf("liste->groupe = %s\n", liste->groupe);
	printf("liste->droit[1] = %c\n", liste->droit[1]);
	printf("liste->droit[4] = %c\n", liste->droit[4]);
	printf("liste->droit[7] = %c\n", liste->droit[7]);

	if (liste->droit[1] == 'r' && ft_strcmp(data->user_data, liste->user) == 0) // proprietaire
		i = 1;
	if (liste->droit[4] == 'r' && ft_strcmp(data->groupe_data, liste->groupe) == 0) // user appartenant au groupe
		i = 1;
	if (liste->droit[7] == 'r') // autre utilisateur
		i = 1;
	return (i);
}

t_lst			*return_access_denied(t_dir **fichierlu)
{
	t_lst	*list;

	list = ft_lstnew_ls();
	list->name = ft_strdup((*fichierlu)->d_name);
	list->access_denied = ft_strdup((*fichierlu)->d_name);
	return (list);
}