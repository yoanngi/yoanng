/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 16:50:36 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	ft_check_options :
**	Create chain list for all directory
**	Print path of the various directory
*/

static int		ft_len_list(t_rep *lst)
{
	t_rep	*cpy;
	int		i;

	cpy = lst;
	i = 0;
	while (cpy)
	{
		i++;
		cpy = cpy->next;
	}
	return (i);
}

static void		ft_target(t_struct *data)
{
	if (ft_len_list(data->multifile) == 0)
	{
		data->nb_file = 1;
		data->multifile = ft_lstnew_argv();
		data->multifile->name = ft_strdup(".");
	}
}

static void		ft_display(t_struct *data)
{
	if (data->lmin == 0)
		ft_print_ls(data);
	else
		ft_print_ls_liste(data);
	if (data->nb_file > 1)
		ft_putchar('\n');
	data->liste = ft_clean_list(&data->liste);
	free(data->liste);
	data->liste = NULL;
}

void			ft_check_options(t_struct *data)
{
	t_rep	*arg;
	int		path;

	arg = data->multifile;
	path = data->nb_file;
	data->liste = NULL;
	ft_target(data);
	while (arg)
	{
		data->liste = ft_ls_r(data, arg->name);
		if (path > 1)
		{
			ft_putstr(arg->name);
			ft_putstr(":\n");
		}
		ft_display(data);
		arg = arg->next;
	}
	ft_clean_t_dir(&data->multifile);
	data->multifile = NULL;
}
