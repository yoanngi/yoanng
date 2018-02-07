/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_return_l.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 13:48:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:49:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_return_time(char *str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(str);
	ret = ft_strsub(cpy, 12, 4);
	ft_strdel(&cpy);
	return (ret);
}

char	*ft_return_month(char *str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(str);
	ret = ft_strsub(str, 4, 3);
	ft_strdel(&cpy);
	return (ret);
}

char	*ft_return_day(char *str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(str);
	ret = ft_strsub(str, 8, 2);
	ft_strdel(&cpy);
	return (ret);
}
