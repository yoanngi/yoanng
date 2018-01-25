/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 10:48:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_add_list(void)
{
	t_lst	*data;

	data = (t_lst *)malloc(sizeof(t_lst));
	if (data == NULL)
		return (NULL);
	data->name = NULL;
	data->params = NULL;
	data->size = 0;
	data->previous = NULL;
	data->next = NULL;
	return &(*data);
}

t_lst	ft_list_add_ls(t_lst *data, t_dir *fichierlu)
{
	DIR		*dir;

	if ((dir = opendir(fichierlu->d_name)) == NULL)
		exit(1);
	ft_putstr("JE SUIS LA\n");
	data->name = ft_strdup((const char *)fichierlu);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		data->size += 1;
		ft_putstr(fichierlu->d_name);
		ft_putstr("\n");
	}
	closedir(dir);
	return (*data);
}

void	ft_print_lst(t_lst *data)
{
	int i;

	i = 0;
	while (data)
	{
		ft_putstr(data->name);
		data = data->next;
	}
}
