/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 11:44:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Count len list
*/

static int		ft_len_list(t_rep *lst)
{
	t_rep	*cpy;
	int		i;

	if (!lst)
		return (0);
	cpy = lst;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	return (i);
}

/*
**	If not directory in list, add directory (.)
*/

static t_rep	*ft_target(t_struct *data)
{
	t_rep	*tmp;

	tmp = NULL;
	data->nb_file = ft_len_list(data->multifile);
	if (data->multifile == NULL && data->filevalid == NULL
	&& data->invalid == 0 && data->nb_file == 0)
	{
		tmp = ft_lstnew_argv();
		tmp->name = ft_strdup(".");
		return (tmp);
	}
	else
	{
		tmp = data->multifile;
		ft_class_repertory(&tmp, data);
	}
	return (tmp);
}

/*
**	print with options -l or not
**	clean list
*/

static void		ft_display(t_struct *data)
{
	if (data->lmin == 0)
		ft_print_ls(data);
	else
		ft_print_ls_liste(data);
	data->liste = ft_clean_list(&data->liste);
	free(data->liste);
	data->liste = NULL;
}

/*
**	Print path and execute options in good directory
*/

static void		ft_options_suite(t_struct *data, t_rep *arg, t_lst **clear)
{
	t_lst	*cpy;

	cpy = *clear;
	if (data->filevalid)
	{
		data->lmin == 1 ? ft_ls_liste(&cpy, 1, 0) : ft_ls_simple_sort(cpy, 1);
		ft_clean_list(clear);
	}
	if (data->filevalid && data->multifile)
		ft_putchar('\n');
	while (arg)
	{
		data->liste = ft_ls_r(data, arg->name);
		if (data->nb_file > 1 || data->filevalid)
		{
			ft_putstr(arg->name);
			ft_putstr(":\n");
		}
		ft_display(data);
		if (arg->next)
			ft_putchar('\n');
		arg = arg->next;
	}
	data->multifile = ft_clean_t_dir(&data->multifile);
	data->filevalid = ft_clean_t_dir(&data->filevalid);
}

void			ft_check_options(t_struct *data)
{
	t_rep	*arg;
	t_rep	*file;
	t_lst	*cpy;
	t_lst	*tmp;

	cpy = NULL;
	file = data->filevalid;
	arg = ft_target(data);
	data->multifile = arg;
	while (file)
	{
		if (cpy == NULL)
		{
			cpy = ft_lstnew_ls();
			tmp = cpy;
		}
		else
		{
			cpy->next = ft_lstnew_ls();
			cpy = cpy->next;
		}
		ft_print_file(&file->name, data, &cpy);
		file = file->next;
	}
	ft_options_suite(data, arg, &tmp);
}
