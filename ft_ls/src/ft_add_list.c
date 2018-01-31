/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 10:23:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_lstnew_ls(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->next = NULL;
	return (new);
}

void	ft_print_lst(s_struct *data)
{
	printf("***********************************Ft_print_lst\n\n");
	ft_ls_simple(data->file);
	ft_putstr("\n");
	while (data->liste)
	{
		if (data->liste->docs != NULL)
		{
			ft_putstr("data->liste->name ->>>>>>");
			ft_putstr(data->liste->name);
			ft_putstr("\n");
			while (data->liste->docs)
			{
				printf("data->liste->docs->name\n");
				ft_putstr(data->liste->docs->name);
				ft_putstr("\n");
				data->liste->docs = data->liste->docs->next;
			}
		}
		ft_putstr("\n");
		data->liste = data->liste->next;
	}
}
