/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 16:40:21 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char *file, int i)
{
	if (i == 1)
	{
		perror("ft_ls : illegal option");
		perror(file);
		perror("\nusage: ls [-Rratl] [file...]\n");
		exit(EXIT_SUCCESS);
	}
	else if (i == 2)
	{
		perror("ft_ls :");
		perror(file);
		perror("No such file or directory\n");
		exit(EXIT_SUCCESS);
	}
}

int		ft_check_permissions(char *path, t_lst **rep)
{

	// Autoriser ? access
	if (access(path, R_OK) & EACCES)
	{
		(*rep)->access = 0;
	//	perror(path);
		return (0);
	}
	else
	{
		(*rep)->access = 1;
		return (1);
	}
}
