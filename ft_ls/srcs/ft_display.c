/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 14:39:32 by yoginet     ###    #+. /#+    ###.fr     */
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

	len = ft_strlen(ft_itoa((*data)->major));
	while (len++ != major + 1)
		ft_putchar(' ');
	ft_putnbr((*data)->major);
	ft_putchar(',');
	len = ft_strlen(ft_itoa((*data)->minor));
	while (len++ != minor + 1)
		ft_putchar(' ');
	ft_putnbr((*data)->minor);
	ft_putstr(" ");
}

/*
**	Print size
*/

static void		ft_print_size(t_lst **data, int size, int minor, int major)
{
	int		len;
	char	*tmp;

	if (minor != 1 || major != 1)
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
		while (len++ != size + 1)
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
		ft_strdel(&(*data)->symbol);
	}
}

/*
**	Print in display (part 1)
*/

void			ft_display_one(t_lst **da, int grp, int link, int use)
{
	int		len;

	ft_putstr((*da)->droit);
	ft_putchar(' ');
	len = ft_strlen(ft_itoa((*da)->link));
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
}
