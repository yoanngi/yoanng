/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_space.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 11:55:52 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 12:08:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checklongmax_size(t_lst **data)
{
	t_lst	*cpy;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	ret = ft_strlen(ft_itoa(cpy->size));
	while (cpy)
	{
		compt = ft_strlen(ft_itoa(cpy->size));
		if (compt > ret)
			ret = compt;
		cpy = cpy->next;
	}
	return (ret);
}

int		ft_checklongmax_link(t_lst **data)
{
	t_lst	*cpy;
	int		compt;
	int		ret;

	compt = 0;
	cpy = (*data);
	ret = ft_strlen(ft_itoa(cpy->link));
	while (cpy)
	{
		compt = ft_strlen(ft_itoa(cpy->link));
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
	ret = ft_strlen(cpy->user);
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
	ret = ft_strlen(cpy->groupe);
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
