/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 14:32:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Create new list
*/

t_lst		*ft_lstnew_ls(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->name = NULL;
	new->symbol = NULL;
	new->path = NULL;
	new->user = NULL;
	new->groupe = NULL;
	new->droit = NULL;
	new->date = 0;
	new->size = 0;
	new->minor = 0;
	new->major = 0;
	new->link = 0;
	new->blocks = 0;
	new->access = 1;
	new->otherfile = NULL;
	new->denied = NULL;
	new->next = NULL;
	if (!new)
		return (NULL);
	return (new);
}

/*
**	swap list chain
*/

t_lst		*lst_swap(t_lst *lst1, t_lst *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}

/*
**	Free list and datas
*/

t_lst		*ft_clean_list(t_lst **data)
{
	t_lst	*clear;
	t_lst	*cpy;

	clear = *data;
	while (clear)
	{
		if (clear->otherfile != NULL)
			ft_clean_list(&clear->otherfile);
		ft_strdel(&clear->path);
		ft_strdel(&clear->droit);
		ft_strdel(&clear->user);
		ft_strdel(&clear->groupe);
		ft_strdel(&clear->name);
		ft_strdel(&clear->symbol);
		cpy = clear;
		clear = clear->next;
		free(cpy);
		cpy = NULL;
	}
	free(clear);
	clear = NULL;
	return (NULL);
}

/*
**	Free tab in struct and free struct
**	Free tab (params)
*/

void		ft_del_struct(t_struct *data, char **tab)
{
	int i;

	i = 0;
	while (i != data->argc)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	i = 0;
	while (i != data->nb_file)
	{
		free(data->multifile[i]);
		data->multifile[i] = NULL;
		i++;
	}
	free(data->multifile);
	data->multifile = NULL;
	free(data->liste);
	data->liste = NULL;
	free(data);
	data = NULL;
}
