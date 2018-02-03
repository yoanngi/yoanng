/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 10:48:27 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 15:23:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_check_permissions(char *path)
{
	if (access(path, R_OK) & EACCES)
		return (0);
	else
		return (1);
}

static void			ft_insert_data(t_dir *fichierlu, t_lst **data, char *path)
{
	(*data)->path = ft_strjoin(path, "/");
	(*data)->path = ft_strjoin((*data)->path, fichierlu->d_name);
}

static t_lst		*ft_read_repertoire(t_dir **fichierlu, char *path)
{
	DIR		*dir;
	t_lst	*rep;
	t_lst	*cpy;

	rep = ft_lstnew_ls();
	cpy	= rep;
	if (ft_check_permissions(path) == 0)
	{
		rep->access = 0;
		printf("ACCES DENIED\n");
		return (rep);
	}
	dir = opendir(path);
	rep->path = ft_strdup(path);
	while ((*fichierlu = readdir(dir)) != NULL)
	{
		printf("ft_read : %s\n", (*fichierlu)->d_name);
		rep->name = ft_strdup((*fichierlu)->d_name);
		if ((*fichierlu)->d_type == 4 && ft_strcmp((*fichierlu)->d_name, ".") != 0 && ft_strcmp((*fichierlu)->d_name, "..") != 0)
		{
			ft_insert_data(*fichierlu, &rep, path);
			rep->otherfile = ft_read_repertoire(fichierlu, rep->path);
		}
		else
			rep->otherfile = NULL;
		rep->access = 1;
		rep->next = ft_lstnew_ls();
		rep = rep->next;
	}
	closedir(dir);
	return (cpy);
}

static t_lst		*ft_ls_r(s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	t_lst		*lstsend;

	lstdata = ft_lstnew_ls();
	lstsend = lstdata;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		printf("ft_ls_r : %s\n", fichierlu->d_name);
		lstdata->name = ft_strdup(fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			ft_insert_data(fichierlu, &lstdata, data->file);
			lstdata->otherfile = ft_read_repertoire(&fichierlu, lstdata->path);
		}
		else
			lstdata->otherfile = NULL;
		lstdata->access = 1;
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
	}
	closedir(dir);
	return (lstsend);
}

void				ft_check_options(s_struct *data)
{
	s_struct	*tmp;

	if (data->file == NULL)
		data->file = ft_strdup(".");
	tmp = data;
	if (data->rmaj == 1)// -R
		data->liste = ft_ls_r(data);
	/*	if (data->rmin == 1)// -r
		ft_option_r(data);
		if (data->tmin == 1)// -t
		ft_sort(data);
		if (data->amin == 1)// -a
		ft_filecacher(data);
	 */
	// Plus qu'a gerer le mode d'affichage
	ft_putstr("*****************Fonction d'affichage*****************\n");
	ft_print_ls(data);
}






























/*		printf("Fichier lu = %s\n", fichierlu->d_name);
		if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
		lstdata->name = ft_strdup(fichierlu->d_name);
		ft_path(lstdata, data->file, fichierlu->d_name);
		lstdata->otherfile = ft_read_repertoire(lstdata, fichierlu);
		lstdata->next = ft_lstnew_ls();
		lstdata = lstdata->next;
		}
		}
		closedir(dir);
		return (lstsend);
		}*/
/*
   static t_lst		*ft_read_repertoire(t_lst *data, t_dir *fichierlu)
   {
   DIR		*dir;
   int		i;
   t_lst	*rep;
   t_lst	*cpy;

   i = 0;
   dir = opendir(data->path);
   printf("%s:\n", data->path);
   if (ft_access_dir(data->path) == 0)
   {
   perror("Acces Denied\n");
   return (NULL);
   }
   ft_ls_simple(data->path);
   rep = ft_lstnew_ls();
   cpy	= rep;
   while ((fichierlu = readdir(dir)) != NULL)
   {
//printf("%s\n", fichierlu->d_name);
if (fichierlu->d_type == 4 && ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
{
i = 1;
rep->name = ft_strdup(fichierlu->d_name);
ft_path(rep, data->path, fichierlu->d_name);
rep->otherfile = ft_read_repertoire(rep, fichierlu);
rep->next = ft_lstnew_ls();
}
}
closedir(dir);
if (i == 0)
return (NULL);
return (cpy);
}


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
