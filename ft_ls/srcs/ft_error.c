/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 13:33:52 by yoginet     ###    #+. /#+    ###.fr     */
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

/*
**	Retourne un maillon avec le nom et path du fichier dont on a pas l'acces
*/

t_lst	*ft_return_access_denied(t_dir **fichierlu, char *path)
{
	t_lst	*rep;

	rep = ft_lstnew_ls();
	rep->path = ft_strdup(path);
	rep->name = ft_strdup((*fichierlu)->d_name);
	rep->otherfile = NULL;
	rep->next = NULL;
	return (rep);
}

/*
**	Print maillon error
*/

void	ft_print_error(t_lst *cpy, int amin)
{
	if (amin == 0 && cpy->name[0] == '.')
		return ;
	ft_putstr("\n");
	ft_putstr(cpy->path);
	ft_strdel(&cpy->path);
	ft_putstr("\n");
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(cpy->name, 2);
	ft_strdel(&cpy->name);
	ft_putstr_fd(": Permission denied\n", 2);
	free(cpy);
	cpy = NULL;
}
