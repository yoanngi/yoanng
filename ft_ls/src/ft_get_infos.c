/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 14:25:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 13:50:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_user(char **path)
{
	struct passwd	*user;
	t_stat			buf;
	char			*cpy;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (NULL);
	}
	user = getpwuid(buf.st_uid);
	cpy = ft_strdup(user->pw_name);
	return (cpy);
}

char	*ft_get_groupe(char **path)
{
	struct group	*groupe;
	t_stat			buf;
	char			*cpy;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (NULL);
	}
	groupe = getgrgid(buf.st_gid);
	cpy = ft_strdup(groupe->gr_name);
	return (cpy);
}

int		ft_get_size(char **path)
{
	t_stat			buf;
	int				cpy;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (0);
	}
	cpy = buf.st_size;
	return (cpy);
}

int		ft_get_link(char **path)
{
	t_stat			buf;
	int				cpy;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (0);
	}
	cpy = buf.st_nlink;
	return (cpy);
}

int		ft_get_blocks(char **path)
{
	t_stat			buf;
	blkcnt_t		cpy;

	if (lstat(*path, &buf) == -1)
	{
		basic_error(*path);
		return (0);
	}
	cpy = buf.st_blocks;
	return (cpy);
}
