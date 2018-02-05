/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 12:40:20 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_check_options(s_struct *data)
{
	if (data->file == NULL)
		data->file = ft_strdup(".");
	if (data->rmaj == 1)
		data->liste = ft_ls_r(data);
	if (data->lmin == 1)
		data->liste = ft_ls_l(data);

/*	if (data->tmin == 1)// -t
		ft_sort(data);
	if (data->amin == 1)// -a
		ft_filecacher(data);
*/
		ft_print_ls_liste(data);
}








/*

static int			ft_access_dir(char *path)
{
t_stat	access;
char *cpy;

cpy = ft_strdup(path);
ft_strdel(&cpy);
if ((stat(path, &access)) < 0)
return (0);
printf("PATH = %s\n", path);
printf("File Permissions: \t");
printf( (S_ISDIR(access.st_mode)) ? "d" : "-");
printf( (access.st_mode & S_IRUSR) ? "r" : "-");
printf( (access.st_mode & S_IWUSR) ? "w" : "-");
printf( (access.st_mode & S_IXUSR) ? "x" : "-");
printf( (access.st_mode & S_IRGRP) ? "r" : "-");
printf( (access.st_mode & S_IWGRP) ? "w" : "-");
printf( (access.st_mode & S_IXGRP) ? "x" : "-");
printf( (access.st_mode & S_IROTH) ? "r" : "-");
printf( (access.st_mode & S_IWOTH) ? "w" : "-");
printf( (access.st_mode & S_IXOTH) ? "x" : "-");
printf("\n\n");
if ((access.st_mode & S_IRUSR) == 0 && (access.st_mode & S_IXUSR) == 0 && (access.st_mode & S_IXOTH) == 0)
return (1);
if ((access.st_mode & S_IRGRP) == 0 || (access.st_mode & S_IROTH) == 0)
return (0);
return (1);
}
static t_lst	*ft_path(t_lst **rep, char *file, char **dossier)
{
(*rep)->path = ft_strjoin(file, "/");
(*rep)->path = ft_strjoin((*rep)->path, *dossier);
return (&rep);
}*/
