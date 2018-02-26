/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 15:07:08 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_file_exist(char *file_ornot, int silent)
{
	DIR		*dir;

	silent = 0;
	if ((dir = opendir(file_ornot)) != NULL)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

int				ft_file_exist_malloc(char *file_ornot)
{
	DIR		*dir;

	if ((dir = opendir(file_ornot)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}
