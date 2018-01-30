/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 14:58:03 by yoginet     ###    #+. /#+    ###.fr     */
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
	printf("ft_print_lst\n\n");
	while (data->liste)
	{
		ft_putstr("tour de boucle\n");
		ft_putstr("data->liste->name ->>>>>>");
		ft_putstr(data->liste->name);
		ft_putstr("\ndata->liste->docs->name ->>>>>  ");
		ft_putstr(data->liste->docs->name);
		ft_putstr("\n");
		if (data->liste->docs != NULL)
		{
			printf("data->liste->docs non NULL\n");
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
