/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_minor_major.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 15:08:45 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 10:56:33 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Minor/Major or size ?
*/

void	ft_minmajorsize(t_stat buf, t_lst **ret)
{
	if ((*ret)->droit[0] == 'c' || (*ret)->droit[0] == 'b')
	{
		(*ret)->minor = ft_get_minor(buf);
		(*ret)->major = ft_get_major(buf);
	}
	else
		(*ret)->size = ft_get_size(buf);
}

/*
**	Apply the mask for detect minor
*/

int		ft_get_minor(t_stat buf)
{
	int			minor;

	minor = buf.st_rdev & ((1U << 24) - 1);
	return (minor);
}

/*
**	Apply the mask for detect major
*/

int		ft_get_major(t_stat buf)
{
	int			major;

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
