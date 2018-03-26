/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:08:13 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 16:48:50 by yoginet     ###    #+. /#+    ###.fr     */
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

void			ft_display_one(t_lst **da, int link, int use)
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
	ft_strdel(&tmp);
}
