/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_good_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 11:07:50 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 11:07:52 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Verifiy is cmd is in directory (target)
*/

static int		good_path_suite(char *cmd, char *name, int ret, char *target)
{
	if (ft_strcmp(cmd, name) == 0)
	{
		if (!(access(target, X_OK) & EACCES))
			ret = 1;
		else
		{
			basic_error("permission denied: ", cmd);
			ret = 0;
		}
	}
	return (ret);
}

int				good_path(char *target, char *cmd)
{
	DIR				*dir;
	struct dirent	*fl;
	char			*tmp;
	int				ret;

	ret = -1;
	tmp = ft_strsub(target, 0, (ft_strlen(target) - ft_strlen(cmd)));
	if ((dir = opendir(tmp)) == NULL)
	{
		ft_strdel(&tmp);
		return (ret);
	}
	ft_strdel(&tmp);
	while (((fl = readdir(dir)) != NULL) && ret == -1)
		ret = good_path_suite(cmd, fl->d_name, ret, target);
	if ((closedir(dir)) == -1)
		return (ret);
	return (ret);
}
