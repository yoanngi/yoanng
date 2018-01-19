/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 11:18:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_ls(int argc, char **argv)
{
	s_struct	*data;
	DIR			*dir;

	dir = NULL;
	data = (s_struct *)malloc(sizeof(s_struct));
	if (argc > 1)
	{
		data->argv = ft_strdup(argv[2]);
	}
	else
	{
		if ((dir = opendir(".")) == NULL)
			exit(1);
		ft_putstr("c'est ouvert\n");
		while (readdir(dir) != NULL)
			fprintf(stdout,"  %s\n", dir->d_name);;
		if (closedir(dir) == -1)
			exit(1);
		ft_putstr("c'est fermer\n");
	}
}
