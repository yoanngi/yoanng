/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos_suite.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 16:08:33 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:00:25 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_get_time(t_dir **fichierlu)
{
	t_stat			buf;
	char			*cpy;

	stat(((*fichierlu)->d_name), &buf);
	cpy = ft_strdup(ctime(&buf.st_mtime));
	return (cpy);
}

static char		ft_get_droit_two(t_dir **fichierlu)
{
	t_stat	buf;

	stat(((*fichierlu)->d_name), &buf);
	if ((S_ISDIR(buf.st_mode)) == 1)
		return ('d');
	else if ((S_ISLNK(buf.st_mode)) == 1)
		return ('l');
	else if ((S_ISSOCK(buf.st_mode)) == 1)
		return ('s');
	else if ((S_ISBLK(buf.st_mode)) == 1)
		return ('b');
	else if ((S_ISFIFO(buf.st_mode)) == 1)
		return ('f');
	else
		return ('-');
}

char			*ft_get_droit(t_dir **fichierlu)
{
	t_stat			buf;
	char			*cpy;

	cpy = ft_strnew(10);
	stat(((*fichierlu)->d_name), &buf);
	cpy[0] = ft_get_droit_two(fichierlu);
	cpy[1] = *((buf.st_mode & S_IRUSR) ? "r" : "-");
	cpy[2] = *((buf.st_mode & S_IWUSR) ? "w" : "-");
	cpy[3] = *((buf.st_mode & S_IXUSR) ? "x" : "-");
	cpy[4] = *((buf.st_mode & S_IRGRP) ? "r" : "-");
	cpy[5] = *((buf.st_mode & S_IWGRP) ? "w" : "-");
	cpy[6] = *((buf.st_mode & S_IXGRP) ? "x" : "-");
	cpy[7] = *((buf.st_mode & S_IROTH) ? "r" : "-");
	cpy[8] = *((buf.st_mode & S_IWOTH) ? "w" : "-");
	cpy[9] = *((buf.st_mode & S_IXOTH) ? "x" : "-");
	cpy[10] = '\0';
	return (cpy);
}
