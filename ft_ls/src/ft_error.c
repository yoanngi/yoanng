/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:07:27 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(s_struct *data, int i)
{
	if (i == 1)
	{
		perror("ft_ls : illegal option -- ");
		perror(data->invalid);
		perror("\nusage: ls [-Rratl] [file...]\n");
	}
	else if (i == 2)
	{
		perror("ft_ls:");
		perror(data->file);
		perror(": No such file or directory\n");
	}
}

int		ft_check_error(char *file)
{
	DIR *dir;

	dir = opendir(file);
	if (EACCES == 0)
	{
		printf("Access Denied : %s\n", file);
		closedir(dir);
		return (1);
	}
	else
		printf("Access Granted : %s\n", file);
	closedir(dir);
	return (0);
}
