/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_liste.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 12:02:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 13:41:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_liste_ls_two(t_lst **data, int size)
{
	int		len;

	len = ft_strlen(ft_itoa((*data)->size));
	while (len++ != size + 1)
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
	if ((*data)->symbol != NULL)
	{
		ft_putstr(" -> ");
		ft_putstr((*data)->symbol);
		ft_strdel(&(*data)->symbol);
	}
}

static void			ft_print_liste_ls(t_lst **data, int grp, int link, int use)
{
	int		len;

	ft_putstr((*data)->droit);
	ft_putchar(' ');
	len = ft_strlen(ft_itoa((*data)->link));
	while (len++ != link + 1)
		ft_putchar(' ');
	ft_putnbr((*data)->link);
	ft_putstr(" ");
	ft_putstr((*data)->user);
	len = ft_strlen((*data)->user);
	while (len++ <= use + 1)
		ft_putchar(' ');
	ft_putstr((*data)->groupe);
	len = ft_strlen((*data)->groupe);
	while (len++ != grp + 1)
		ft_putchar(' ');
}

static void			ft_ls_liste_amin(t_lst **data, int size, int link)
{
	int		use;
	int		grp;
	t_lst	*cpy;

	use = ft_checklongmax_user(data);
	grp = ft_checklongmax_group(data);
	cpy = *data;
	while (cpy)
	{
		ft_print_liste_ls(&cpy, grp, link, use);
		ft_print_liste_ls_two(&cpy, size);
		ft_putstr("\n");
		ft_del_infos(&cpy);
		cpy = cpy->next;
	}
}

static void			ft_ls_liste_noamin(t_lst **data, int size, int link)
{
	int		use;
	int		grp;
	t_lst	*cpy;

	use = ft_checklongmax_user(data);
	grp = ft_checklongmax_group(data);
	cpy = *data;
	while (cpy->next)
	{
		if (cpy->name == NULL || cpy->next == NULL)
			return ;
		if (cpy->name[0] == '.')
		{
			ft_del_infos(&cpy);
			cpy = cpy->next;
		}
		else
		{
			ft_print_liste_ls(&cpy, grp, link, use);
			ft_print_liste_ls_two(&cpy, size);
			ft_putchar('\n');
			ft_del_infos(&cpy);
			cpy = cpy->next;
		}
	}
}

void				ft_ls_liste(t_lst **data, int secret)
{
	int		size;
	int		link;

	size = ft_checklongmax_size(data);
	link = ft_checklongmax_link(data);
	if (secret == 1)
		ft_ls_liste_amin(data, size, link);
	if (secret == 0)
		ft_ls_liste_noamin(data, size, link);
}
