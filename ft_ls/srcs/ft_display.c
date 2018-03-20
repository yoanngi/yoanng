/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 16:10:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Print Major or Minor
*/

static void		ft_print_min_maj(t_lst **data, int minor, int major)
{
	int		len;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_itoa((*data)->major);
	tmp2 = ft_itoa((*data)->minor);
	len = ft_strlen(tmp1);
	while (len++ != major + 1)
		ft_putchar(' ');
	ft_putnbr((*data)->major);
	ft_putchar(',');
	len = ft_strlen(tmp2);
	while (len++ != minor + 1)
		ft_putchar(' ');
	ft_putnbr((*data)->minor);
	ft_putstr(" ");
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
}

/*
**	Print size
*/

static void		ft_print_size(t_lst **data, int size, int minor, int major)
{
	int		len;
	char	*tmp;

	if ((minor != 1 || major != 1) && size < minor + major)
	{
		while (minor-- >= 0)
			ft_putchar(' ');
		while (major-- >= 0)
			ft_putchar(' ');
	}
	else
	{
		tmp = ft_itoa((*data)->size);
		len = ft_strlen(tmp);
		ft_strdel(&tmp);
		while (len++ != size + 2)
			ft_putchar(' ');
	}
	ft_putnbr((*data)->size);
	ft_putstr(" ");
}

/*
**	Print in display (part 2)
*/

void			ft_display_two(t_lst **data, int size, int mi, int ma)
{
	if ((*data)->droit[0] == 'c' || (*data)->droit[0] == 'b')
		ft_print_min_maj(data, mi, ma);
	else
		ft_print_size(data, size, mi, ma);
	ft_return_month((*data)->date);
	ft_putstr(" ");
	ft_return_day((*data)->date);
	ft_putstr(" ");
	ft_return_time((*data)->date);
	ft_putstr(" ");
	ft_putstr((*data)->name);
	if ((*data)->symbol != NULL)
	{
		ft_putstr(" -> ");
		ft_putstr((*data)->symbol);
	}
}

/*
**	Print in display (part 1)
*/

void			ft_display_one(t_lst **da, int grp, int link, int use)
{
	int		len;
	char	*tmp;

	tmp = ft_itoa((*da)->link);
	ft_putstr((*da)->droit);
	ft_putchar(' ');
	len = ft_strlen(tmp);
	while (len++ != link + 1)
		ft_putchar(' ');
	ft_putnbr((*da)->link);
	ft_putstr(" ");
	ft_putstr((*da)->user);
	len = ft_strlen((*da)->user);
	while (len++ <= use + 1)
		ft_putchar(' ');
	ft_putstr((*da)->groupe);
	len = ft_strlen((*da)->groupe);
	while (len++ != grp + 1)
		ft_putchar(' ');
	ft_strdel(&tmp);
}

/*
**	take infos and print file argv
*/

void			ft_print_file(char **path, t_struct *data)
{
	t_stat	buf;
	t_lst	*ret;

	ret = NULL;
	if (lstat(*path, &buf) == -1)
		return ;
	data->invalid = 1;
	ret = ft_lstnew_ls();
	ret->name = ft_strdup(*path);
	ret->droit = ft_get_droit(buf);
	ret->user = ft_get_user(buf);
	ret->groupe = ft_get_groupe(buf);
	ret->date = ft_get_time(buf);
	ft_minmajorsize(buf, &ret);
	ret->link = ft_get_link(buf);
	ret->blocks = ft_get_blocks(buf);
	ret->access = ft_access_or_not(path);
	ret->symbol = NULL;
	if (ret->droit[0] == 'l')
		ret->symbol = ft_get_new_path(path);
	data->lmin == 1 ? ft_ls_liste(&ret, 1) : ft_putendl(*path);
	ret = ft_clean_list(&ret);
}
