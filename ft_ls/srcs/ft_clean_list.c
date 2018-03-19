/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clean_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 16:13:01 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 13:24:39 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Free list and datas
*/

t_lst		*ft_clean_list(t_lst **data)
{
	t_lst	*clear;
	t_lst	*cpy;

	if (!*data)
		return (NULL);
	clear = *data;
	while (clear)
	{
		if (clear->otherfile)
			clear->otherfile = ft_clean_list(&clear->otherfile);
		ft_strdel(&clear->path);
		ft_strdel(&clear->droit);
		ft_strdel(&clear->user);
		ft_strdel(&clear->groupe);
		ft_strdel(&clear->name);
		ft_strdel(&clear->symbol);
		cpy = clear;
		clear = clear->next;
		free(cpy);
		cpy = NULL;
	}
	free(clear);
	clear = NULL;
	return (NULL);
}

/*
**	Free list t_dir and data
*/

t_rep		*ft_clean_t_dir(t_rep **data)
{
	t_rep	*clear;
	t_rep	*cpy;

	if (!*data)
		return (NULL);
	clear = *data;
	while (clear)
	{
		ft_strdel(&clear->name);
		cpy = clear;
		clear = clear->next;
		free(cpy);
		cpy = NULL;
	}
	free(clear);
	clear = NULL;
	return (NULL);
}

/*
**	Free struct
*/

t_struct		*ft_del_struct(t_struct *data)
{
	free(data->multifile);
	data->multifile = NULL;
	free(data->liste);
	data->liste = NULL;
	free(data);
	data = NULL;
	return (NULL);
}
