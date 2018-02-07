/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 14:25:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 16:44:38 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_user(t_dir **fichierlu, char *path)
{
	struct passwd	*user;
	t_stat			buf;
	char			*cpy;
	char			*tmp;

	// A tester
	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, (*fichierlu)->d_name);
	if (stat(((*fichierlu)->d_name), &buf) == -1)
	{
		perror((*fichierlu)->d_name);
		exit(EXIT_SUCCESS);
	}
	free(&tmp);
	user = getpwuid(buf.st_uid);
	cpy = ft_strdup(user->pw_name);
	return (cpy);
}

char	*ft_get_groupe(t_dir **fichierlu)
{
	struct group	*groupe;
	t_stat			buf;
	char			*cpy;

	if (stat(((*fichierlu)->d_name), &buf) == -1)
	{
		perror((*fichierlu)->d_name);
		exit(EXIT_SUCCESS);
	}
	groupe = getgrgid(buf.st_gid);
	cpy = ft_strdup(groupe->gr_name);
	return (cpy);
}

int		ft_get_size(t_dir **fichierlu)
{
	t_stat			buf;
	int				cpy;

	if (stat(((*fichierlu)->d_name), &buf) == -1)
	{
		perror((*fichierlu)->d_name);
		exit(EXIT_SUCCESS);
	}
	cpy = buf.st_size;
	return (cpy);
}

int		ft_get_link(t_dir **fichierlu)
{
	t_stat			buf;
	int				cpy;

	if (stat(((*fichierlu)->d_name), &buf) == -1)
	{
		perror((*fichierlu)->d_name);
		exit(EXIT_SUCCESS);
	}
	cpy = buf.st_nlink;
	return (cpy);
}
