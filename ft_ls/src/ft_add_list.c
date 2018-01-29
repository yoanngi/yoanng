/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_add_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:15 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 15:30:56 by yoginet     ###    #+. /#+    ###.fr     */
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
	DIR	*cpy;

	printf("ft_print_lst\n\n");
	while (data->liste)
	{
		ft_putstr("tour de boucle\n");
		ft_putstr(data->liste->name);
		if (data->liste->type == 4)
		{
			cpy = opendir(data->liste->name);
			while ((data->liste->fd = readdir(cpy)) != NULL)
			{
				ft_putstr(data->liste->fd->d_name);
				ft_putstr("\n");
			}
			closedir(cpy);
		}
		ft_putstr("\n");
		data->liste = data->liste->next;
	}
}