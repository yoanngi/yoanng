/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_minor_major.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:08:45 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 15:09:34 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Apply the mask for detect minor
*/

int		ft_get_minor(char **path)
{
	t_stat		buf;
	int			minor;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (0);
	}
	minor = buf.st_rdev & ((1U << 24) - 1);
	return (minor);
}

/*
**	Apply the mask for detect major
*/

int		ft_get_major(char **path)
{
	t_stat		buf;
	int			major;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (0);
	}
	major = (buf.st_rdev >> 24);
	return (major);
}

/*
**	Long max minor
*/

int		ft_checklongmax_minor(t_lst **data)
{
	t_lst	*cpy;
	char	*tmp;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	tmp = ft_itoa(cpy->minor);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	while (cpy)
	{
		if (cpy->name != NULL)
		{
			tmp = ft_itoa(cpy->minor);
			compt = ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}

/*
**	Long max major
*/

int		ft_checklongmax_major(t_lst **data)
{
	t_lst	*cpy;
	char	*tmp;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	tmp = ft_itoa(cpy->major);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	while (cpy)
	{
		if (cpy->name != NULL)
		{
			tmp = ft_itoa(cpy->major);
			compt = ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}
