/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos_suite.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 16:08:33 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:28:56 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_return_time(char *str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(str);
	ret = ft_strsub(cpy, 12, 4);
	ft_strdel(&cpy);
	return (ret);
}

char	*ft_return_month(char *str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(str);
	ret = ft_strsub(str, 4, 3);
	ft_strdel(&cpy);
	return (ret);
}

char	*ft_return_day(char *str)
{
	char *cpy;
	char *ret;

	cpy = ft_strdup(str);
	ret = ft_strsub(str, 8, 2);
	ft_strdel(&cpy);
	return (ret);
}

char	*ft_get_time(t_dir **fichierlu)
{
	t_stat			buf;
	char			*cpy;

	stat(((*fichierlu)->d_name), &buf);
	cpy = ft_strdup(ctime(&buf.st_mtime));
	return (cpy);
}

char	*ft_get_droit(t_dir **fichierlu)
{
	t_stat			buf;
	char			*cpy;

	cpy = ft_strnew(10);
	stat(((*fichierlu)->d_name), &buf);
	// A modifier
	cpy[0] = *((S_ISDIR(buf.st_mode)) ? "d" : "-");
	cpy[0] = *((S_ISLNK(buf.st_mode)) ? "l" : "-");
	cpy[0] = *((S_ISSOCK(buf.st_mode)) ? "s" : "-");
	cpy[0] = *((S_ISBLK(buf.st_mode)) ? "b" : "-");
	cpy[0] = *((S_ISFIFO(buf.st_mode)) ? "f" : "-");
	//
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
