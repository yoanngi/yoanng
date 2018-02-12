/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 13:17:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_test_curent(char *path, char *name, int silent)
{
	DIR		*dir;
	t_dir	*fd;

	if ((dir = opendir(path)) < 0)
		return (0);
	while ((fd = readdir(dir)) != NULL)
	{
		if (ft_strcmp(fd->d_name, name) == 0)
		{
			if (silent == 1)
				return (1);
			ft_putstr(name);
			ft_putchar('\n');
			return (0);
		}
	}
	return (0);
}

static int		ft_test_father(char *str, int silent)
{
	int		i;
	int		res;
	size_t	len;
	char	*path;
	char	*name;

	i = 0;
	len = ft_strlen(str);
	while (str[len] || len != 0)
	{
		if (str[len] == '/')
		{
			path = ft_strsub(str, 0, len);
			name = ft_strsub(str, len, i);
			res = ft_test_curent(path, name, silent);
			ft_strdel(&path);
			ft_strdel(&name);
			return (res);
		}
		i++;
		len--;
	}
	return (0);
}

int				ft_file_exist(char *file_ornot, int silent)
{
	DIR		*dir;
	int		i;

	i = 0;
	if ((dir = opendir(file_ornot)) != NULL)
	{
		closedir(dir);
		return (1);
	}
	while (file_ornot[i])
	{
		if (file_ornot[i] == '/')
			return (ft_test_father(file_ornot, silent));
		i++;
	}
	return (ft_test_curent(".", file_ornot, silent));
}

int				ft_file_exist_malloc(char *file_ornot)
{
	DIR		*dir;

	if ((dir = opendir(file_ornot)) == NULL)
		return (0);
	closedir(dir);
	return (0);
}
