/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos_suite.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 16:08:33 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 11:10:51 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

time_t			ft_get_time(char **path)
{
	t_stat			buf;

	lstat(*path, &buf);
	return (*(&buf.st_mtime));
}

char			*ft_get_new_path(char **path)
{
	t_stat	buf;
	char	*cpy;
	char	*ret;

	cpy = ft_strdup(*path);
	ft_strdel(path);
	lstat(cpy, &buf);
	ret = ft_get_droit_symbolique(&cpy, buf.st_size + 1);
	ft_strdel(&cpy);
	ft_strdel(path);
	return (ret);
}

char			*ft_get_droit_symbolique(char **path, size_t size)
{
	char	*ret;
	int		i;
	size_t	secure;

	i = 0;
	ret = (char *)malloc(sizeof(char) * size);
	secure = readlink(*path, ret, size);
	while (ret[i])
	{
		if (ret[i] == ' ' || ret[i] == '\n')
		{
			while (ret[i])
			{
				ret[i] = '\0';
				i++;
			}
			return (ret);
		}
		i++;
	}
	return (ret);
}

char			ft_get_droit_two(char **path)
{
	t_stat	buf;

	lstat(*path, &buf);
	if ((S_ISDIR(buf.st_mode)) == 1)
		return ('d');
	else if ((S_ISLNK(buf.st_mode)) == 1)
		return ('l');
	else if ((S_ISSOCK(buf.st_mode)) == 1)
		return ('s');
	else if ((S_ISBLK(buf.st_mode)) == 1)
		return ('b');
	else if ((S_ISFIFO(buf.st_mode)) == 1)
		return ('p');
	else if ((S_ISCHR(buf.st_mode)) == 1)
		return ('c');
	else
		return ('-');
}

char			*ft_get_droit(char **path)
{
	t_stat			buf;
	char			*cpy;

	cpy = ft_strnew(10);
	lstat(*path, &buf);
	cpy[0] = ft_get_droit_two(path);
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
