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
**	Count len list
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

/*
**	If not directory in list, add directory (.)
*/

static t_rep	*ft_target(t_struct *data)
{
	t_rep	*ret;

	ret = NULL;
	data->nb_file = ft_len_list(data->multifile);
	if (data->nb_file == 0)
	{
		ret = ft_lstnew_argv();
		ret->name = ft_strdup(".");
	}
	else
		ret = data->multifile;
	return (ret);
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

void			ft_check_options(t_struct *data)
{
	t_rep	*arg;
	t_rep	*file;

	printf("Seg\n");
	file = data->filevalid;
	arg = ft_target(data);
	printf("Seg\n");
	while (file)
	{
		if (file->name != NULL)
			ft_print_file(&file->name, data);
		file = file->next;
	}
	ft_putchar('\n');
	while (arg)
	{
		data->liste = ft_ls_r(data, arg->name);
		if (data->nb_file > 1)
		{
			ft_putstr(arg->name);
			ft_putstr(":\n");
		}
		ft_display(data);
		ft_putchar('\n');
		arg = arg->next;
	}
	ft_clean_t_dir(&data->multifile);
	ft_clean_t_dir(&data->filevalid);
	data->multifile = NULL;
	data->filevalid = NULL;
}
