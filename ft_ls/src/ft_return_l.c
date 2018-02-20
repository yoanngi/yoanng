/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_return_l.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 13:48:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 15:18:11 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_yearornot(time_t str)
{
	time_t	now;
	size_t	dif;

	time(&now);
	dif = now - str;
	if (dif > 15778800)
		return (1);
	return (0);
}

char			*ft_return_time(time_t str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(ctime(&str));
	if (ft_yearornot(str) == 1)
		ret = ft_strsub(cpy, 19, 5);
	else
		ret = ft_strsub(cpy, 11, 5);
	ft_strdel(&cpy);
	return (ret);
}

char			*ft_return_month(time_t str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(ctime(&str));
	ret = ft_strsub(cpy, 4, 3);
	ft_strdel(&cpy);
	return (ret);
}

char			*ft_return_day(time_t str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(ctime(&str));
	ret = ft_strsub(cpy, 8, 2);
	ft_strdel(&cpy);
	return (ret);
}

void			ft_print_blocks(t_lst **liste)
{
	t_lst	*cpy;
	int		total;

	total = 0;
	cpy = *liste;
	while (cpy)
	{
		total += cpy->blocks;
		cpy = cpy->next;
	}
	ft_putnbr(total);
	ft_putstr("\n");
}
