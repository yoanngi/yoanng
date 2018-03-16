/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_space.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 11:55:52 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 10:41:15 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Check len max of size, link, user, group
*/

int		ft_checklongmax_size(t_lst **data)
{
	t_lst	*cpy;
	char	*tmp;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	tmp = ft_itoa(cpy->size);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	while (cpy)
	{
		if (cpy->name != NULL)
		{
			tmp = ft_itoa(cpy->size);
			compt = ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}

int		ft_checklongmax_link(t_lst **data)
{
	t_lst	*cpy;
	char	*tmp;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	tmp = ft_itoa(cpy->link);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	while (cpy)
	{
		if (cpy->name != NULL)
		{
			tmp = ft_itoa(cpy->link);
			compt = ft_strlen(tmp);
			ft_strdel(&tmp);
		}
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}

int		ft_checklongmax_user(t_lst **data)
{
	t_lst	*cpy;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	if (cpy->user != NULL)
		ret = ft_strlen(cpy->user);
	else
		return (0);
	while (cpy)
	{
		if (cpy->user != NULL)
			compt = ft_strlen(cpy->user);
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}

int		ft_checklongmax_group(t_lst **data)
{
	t_lst	*cpy;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	if (cpy->groupe != NULL)
		ret = ft_strlen(cpy->groupe);
	else
		return (0);
	while (cpy)
	{
		if (cpy->groupe != NULL)
			compt = ft_strlen(cpy->groupe);
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}
