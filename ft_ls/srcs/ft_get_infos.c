/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 14:25:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 10:57:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Return user
*/

char	*ft_get_user(t_stat buf)
{
	struct passwd	*user;
	char			*cpy;

	if ((user = getpwuid(buf.st_uid)) == NULL)
	{
		cpy = ft_itoa(buf.st_uid);
		return (cpy);
	}
	cpy = ft_strdup(user->pw_name);
	return (cpy);
}

/*
**	return groupe
*/

char	*ft_get_groupe(t_stat buf)
{
	struct group	*groupe;
	char			*cpy;

	if ((groupe = getgrgid(buf.st_gid)) == NULL)
	{
		cpy = ft_itoa(buf.st_gid);
		return (cpy);
	}
	cpy = ft_strdup(groupe->gr_name);
	return (cpy);
}

/*
**	Return size
*/

int		ft_get_size(t_stat buf)
{
	int				cpy;

	cpy = buf.st_size;
	return (cpy);
}

/*
**	Return nb link
*/

int		ft_get_link(t_stat buf)
{
	int				cpy;

	cpy = buf.st_nlink;
	return (cpy);
}

/*
**	Return size block
*/

int		ft_get_blocks(t_stat buf)
{
	blkcnt_t		cpy;

	cpy = buf.st_blocks;
	return (cpy);
}
