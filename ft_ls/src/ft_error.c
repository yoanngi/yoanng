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

void	ft_error(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-Rratl] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	basic_error(char *error)
{
	ft_putstr_fd("ls:", 2);
	perror(error);
	ft_putstr_fd(" No such file or directory\n", 2);
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
