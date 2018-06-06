/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dir_exist.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 09:38:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 15:39:10 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	Directory exist of not
*/

int			ft_dir_exist(char *path)
{
	DIR		*dir;

	if (!(dir = opendir(path)))
		return (0);
	closedir(dir);
	return (1);
}
