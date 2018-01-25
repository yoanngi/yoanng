/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls_simple.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 11:33:33 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_simple(char *target)
{
	DIR			*dir;
	t_dir		*fichierlu;

	if ((dir = opendir(target)) == NULL)
	{
		perror("Impossible d'ouvrir le fichier\n");
		exit(1);
	}
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if ((ft_strcmp(fichierlu->d_name, "..") != 0) &&
	(fichierlu->d_name[0] != '.'))
		{
			ft_putstr(fichierlu->d_name);
			ft_putstr("\n");
		}
	}
	closedir(dir);
}

