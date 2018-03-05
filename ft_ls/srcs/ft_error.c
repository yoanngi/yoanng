/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 13:25:30 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	All function error
*/
void	ft_error(char arg)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(arg, 2);
	ft_putstr_fd("\nusage: ft_ls [-Rratl] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void	basic_error(char *error)
{
	ft_putstr_fd("ls: ", 2);
	perror(error);
}

void	ft_error_access(char *error)
{
	ft_putstr_fd("ls:", 2);
	perror(error);
	ft_putstr_fd(" Permission denied -> perso\n", 2);
}

int		ft_check_permissions(char *path, t_lst **rep)
{
	if (access(path, R_OK) & EACCES)
	{
		(*rep)->access = 0;
		return (0);
	}
	else
	{
		(*rep)->access = 1;
		return (1);
	}
}
