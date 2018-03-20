/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file_suite.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 13:31:51 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 16:49:55 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Check if directory or if symbolique
*/

static int		ft_symbolique(char *path)
{
	t_stat	buf;
	char	*tmp;

	if (lstat(path, &buf) == -1)
		return (0);
	tmp = ft_get_droit(buf);
	if (tmp[0] == 'l')
	{
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

int				ft_access_or_not_start(char **path)
{
	DIR		*dir;
	size_t	len;
	char	*tmp;

	tmp = ft_strdup(*path);
	len = ft_strlen(tmp);
	if (len > 2)
	{
		if (tmp[len - 1] != '/' && ft_symbolique(tmp) == 1)
		{
			ft_strdel(&tmp);
			return (0);
		}
	}
	if ((dir = opendir(tmp)) == NULL)
	{
		ft_strdel(&tmp);
		return (0);
	}
	closedir(dir);
	ft_strdel(&tmp);
	return (1);
}
