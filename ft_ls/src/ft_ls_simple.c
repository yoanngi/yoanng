/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 11:35:02 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_ls_in_order(t_lst **print)
{
	t_lst *clear;

	clear = *print;
	while (*print)
	{
		ft_putstr((*print)->name);
		ft_putstr("\n");
		*print = (*print)->next;
	}
}

t_lst			*ft_class_print(t_lst **data)
{
	t_lst	*cpy;
	t_lst	*ret;
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	cpy = *data;
	ret = *data;
	cpy = cpy->next;
	if (!(*data) || (*data)->name == NULL || (cpy->name == NULL &&
	cpy->next == NULL))
		return (ret);
	while ((*data)->name != NULL && cpy->name != NULL)
	{
		if (ft_strcmp((*data)->name, cpy->name) > 0)
		{
			ft_swap_lst(data, &cpy);
			i = 1;
		}
		cmp++;
		if (cpy->next != NULL || (*data)->next != NULL)
		{
			cpy = cpy->next;
			*data = (*data)->next;
		}
		else if (cmp > 2 && i == 1)
		{
			free(cpy);
			ft_class_print(&ret);
		}
	}
	if (cmp > 2 && i == 1)
		ft_class_print(&ret);
	return (ret);
}

void			ft_ls_simple(char *target)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*data;
	t_lst		*print;
	t_lst		*print2;

	data = ft_lstnew_ls();
	print = data;
	print2 = data;
	if ((dir = opendir(target)) == NULL)
		printf("ERROR, ft_ls_simple, target = %s\n", target);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(fichierlu->d_name, "..") != 0) &&
				(fichierlu->d_name[0] != '.'))
		{
			data->name = ft_strdup(fichierlu->d_name);
			data->next = ft_lstnew_ls();
			data = data->next;
		}
	}
	closedir(dir);
	ft_class_print(&print);
	ft_print_ls_in_order(&print2);
}

static void			ft_print_liste_ls(t_lst **data, int size, int link)
{
	int len;

	ft_putstr((*data)->droit);
	ft_putstr("  ");
	len = ft_strlen(ft_itoa((*data)->link));
	while (len++ != link)
		ft_putchar(' ');
	ft_putnbr((*data)->link);
	ft_putstr(" ");
	ft_putstr((*data)->user);
	ft_putstr("  ");
	ft_putstr((*data)->groupe);
	ft_putstr("  ");
	len = ft_strlen(ft_itoa((*data)->size));
	while (len++ != size)
		ft_putchar(' ');
	ft_putnbr((*data)->size);
	ft_putstr(" ");
	ft_putstr((*data)->month);
	ft_putstr(" ");
	ft_putstr((*data)->day);
	ft_putstr(" ");
	ft_putstr((*data)->time);
	ft_putstr(" ");
	ft_putstr((*data)->name);
}

void			ft_ls_liste(t_lst **data, int secret)
{
	int size;
	int link;

	size = ft_checklongmax_size(data);
	link = ft_checklongmax_link(data);
	while (*data)
	{
		if (!(*data)->droit)
			return ;
		if (secret == 0)
		{
			if ((*data)->name[0] == '.' || ft_strcmp((*data)->name,
	"..") == 0)
				*data = (*data)->next;
			else
			{
				ft_print_liste_ls(data, size, link);
				ft_putstr("\n");
				*data = (*data)->next;
			}
		}
		if (secret == 1)
		{
			ft_print_liste_ls(data, size, link);
			ft_putstr("\n");
			*data = (*data)->next;
		}
	}
}
