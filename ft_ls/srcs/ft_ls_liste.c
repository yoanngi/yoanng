/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_liste.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 12:02:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 10:44:16 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_ls_liste_amin(t_lst **data, int size, int link)
{
	int		use;
	int		grp;
	int		minor;
	int		major;
	t_lst	*cpy;

	minor = ft_checklongmax_minor(data);
	major = ft_checklongmax_major(data);
	use = ft_checklongmax_user(data);
	grp = ft_checklongmax_group(data);
	cpy = *data;
	while (cpy)
	{
		ft_display_one(&cpy, grp, link, use);
		ft_display_two(&cpy, size, minor, major);
		ft_putstr("\n");
		cpy = cpy->next;
	}
}

static void			ft_ls_liste_noamin(t_lst **data, int size, int link)
{
	int		use;
	int		grp;
	int		minor;
	int		major;
	t_lst	*cpy;

	minor = ft_checklongmax_minor(data);
	major = ft_checklongmax_major(data);
	use = ft_checklongmax_user(data);
	grp = ft_checklongmax_group(data);
	cpy = *data;
	while (cpy)
	{
		if (cpy->name != NULL)
		{
			if (cpy->name[0] != '.')
			{
				ft_display_one(&cpy, grp, link, use);
				ft_display_two(&cpy, size, minor, major);
				ft_putchar('\n');
			}
		}
		cpy = cpy->next;
	}
}

void				ft_ls_liste(t_lst **data, int secret)
{
	int		size;
	int		link;

	size = ft_checklongmax_size(data);
	link = ft_checklongmax_link(data);
	if (secret == 1)
		ft_ls_liste_amin(data, size, link);
	if (secret == 0)
		ft_ls_liste_noamin(data, size, link);
}
