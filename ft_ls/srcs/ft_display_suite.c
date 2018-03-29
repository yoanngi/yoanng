/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_suite.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 11:30:08 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:43:00 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		verif(t_stat *buf, char **path)
{
	if (buf->st_mode & S_IFDIR)
	{
		if (errno & EACCES)
		{
			basic_error(*path);
			errno = 0;
			return (0);
		}
		errno = 0;
	}
	return (1);
}

/*
**	take infos and print file argv
*/

void			ft_print_file(char **path, t_struct *data, t_lst **ret)
{
	t_stat	buf;

	if (lstat(*path, &buf) == -1)
		return ;
	if (verif(&buf, path) == 0)
		return ;
	data->invalid = 1;
	(*ret)->name = ft_strdup(*path);
	(*ret)->droit = ft_get_droit(buf);
	(*ret)->user = ft_get_user(buf);
	(*ret)->groupe = ft_get_groupe(buf);
	(*ret)->date = ft_get_time(buf);
	ft_minmajorsize(buf, ret);
	(*ret)->link = ft_get_link(buf);
	(*ret)->blocks = ft_get_blocks(buf);
	(*ret)->access = ft_access_or_not(path);
	(*ret)->symbol = NULL;
	if ((*ret)->droit[0] == 'l')
		(*ret)->symbol = ft_get_new_path(path);
}

/*
**	Print groupe or not
*/

void			ft_display_grp(int grp, t_lst **da)
{
	int len;

	ft_putstr((*da)->groupe);
	len = ft_strlen((*da)->groupe);
	while (len++ != grp + 1)
		ft_putchar(' ');
}
