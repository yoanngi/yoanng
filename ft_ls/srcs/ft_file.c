/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 16:02:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Acces au fichier ou non
*/

int				ft_access_or_not(char **path)
{
	DIR		*dir;

	if ((dir = opendir(*path)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}

/*
**	Retourne un maillon avec le nom et path du fichier dont on a pas l'access
*/

t_lst			*ft_return_access_denied(t_dir **fichierlu, char *path)
{
	t_lst	*rep;

	rep = ft_lstnew_ls();
	rep->path = ft_strdup(path);
	rep->name = ft_strdup((*fichierlu)->d_name);
	return (rep);	
}

/*
**	Retourne str sans / a la fin
*/
char		*ft_strdup_valib(char *str)
{
	size_t	len;
	char	*tmp;

	tmp = NULL;
	len = ft_strlen(str);
	if (len == 1 && str[1] == '/')
		return (str);
	if (len > 1)
	{
		if (str[len - 1] == '/')
		{
			tmp = ft_strsub(str, 0, len - 1);
			return (tmp);
		}
	}
	return (str);
}

/*
**	Le fichier est valide ?
*/

int			ft_is_file(char **path, s_struct *data)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*lstdata;
	int			i;

	i = 0;
	lstdata = ft_lstnew_ls();
	dir = opendir(".");
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if (ft_strcmp(fichierlu->d_name, *path) == 0)
		{
			lstdata->path = ft_strjoin("./", fichierlu->d_name);
			ft_insert_data_hard(&fichierlu, &lstdata, lstdata->path);
			i = 1;
			data->just_file = 1;
		}
	}
	if (i > 0)
	{
		if (data->lmin == 1)
			ft_ls_liste(&lstdata, data->amin);
		else
			ft_putendl(lstdata->name);
			ft_putstr("\n");
	}
	closedir(dir);
	return (i);
}