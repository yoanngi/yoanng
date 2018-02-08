/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_space.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 11:55:52 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 11:55:53 by yoginet     ###    #+. /#+    ###.fr     */
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
