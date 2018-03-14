/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_return_l.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 13:48:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 13:20:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	print year or not
*/

static int		ft_yearornot(time_t str)
{
	time_t			now;
	long long		dif;

	time(&now);
	dif = now - str;
	if (dif > 15778800 || dif < 0)
		return (1);
	return (0);
}

/*
**	Print year of time
*/

void			ft_return_time(time_t str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(ctime(&str));
	if (ft_yearornot(str) == 1)
		ret = ft_strsub(cpy, 19, 5);
	else
		ret = ft_strsub(cpy, 11, 5);
	ft_strdel(&cpy);
	ft_putstr(ret);
	ft_strdel(&ret);
}

/*
**	Print month
*/

void			ft_return_month(time_t str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(ctime(&str));
	ret = ft_strsub(cpy, 4, 3);
	ft_strdel(&cpy);
	ft_putstr(ret);
	ft_strdel(&ret);
}

/*
**	Print day
*/

void			ft_return_day(time_t str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(ctime(&str));
	ret = ft_strsub(cpy, 8, 2);
	ft_strdel(&cpy);
	ft_putstr(ret);
	ft_strdel(&ret);
}
