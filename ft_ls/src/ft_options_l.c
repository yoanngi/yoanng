/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_options_l.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 11:23:44 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:14:46 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static void			ft_add_info(t_lst **rep, t_dir **fichierlu)
{
	t_stat		mystat;

	printf("ft_add_info\n");
	stat((*fichierlu)->d_name, &mystat);
	//(*rep)->droit = ft_check_droit(fichierlu, &mystat);
	(*rep)->link = mystat.st_nlink;
	(*rep)->size = &mystat.st_size;
	//(*rep)->month = ft_check_date(fichierlu, &mystat);
	//(*rep)->day = ft_check_date(fichierlu, &mystat);
	(*rep)->time = &mystat.st_ctime;
	printf("ft_add_info END\n");
}*/

static t_lst		*ft_recupere_info(s_struct *data, t_lst *ret)
{
	DIR			*dir;
	t_dir		*fichierlu;
	t_lst		*cpy;

	cpy = ret;
	dir = opendir(data->file);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		if (ft_strcmp(fichierlu->d_name, ".") != 0 && ft_strcmp(fichierlu->d_name, "..") != 0)
		{
			ret->user = ft_get_user(&fichierlu);
			ret->groupe = ft_get_groupe(&fichierlu);
			printf("Fichierlu = %s, user : %s, groupe : %s", fichierlu->d_name, ret->user, ret->groupe);

			//ft_add_info(ret, &fichierlu);
			//(*ret)->user = &mystat.st_uid;
		}
		//*ret = ft_lstnew_ls();
		//*ret = (*ret)->next;
	}
	closedir(dir);
	return (cpy);
}

t_lst				*ft_ls_l(s_struct *data)
{
	t_lst	*ret;
	t_lst	*cpy;

	if (data->liste != NULL)
	{
		ret = data->liste;
		return (ret);
	}
	else
		ret = ft_lstnew_ls();
	cpy = ft_recupere_info(data, ret);
	free(ret);
	return (cpy);
}

/*
	stat(fichierlu->d_name, &buf);
	printf("******************************Fichier lu = %s\n", fichierlu->d_name);
	printf("Protection		-> st_mode = %o\n", buf.st_mode);
	printf("nb de lien		-> nlink_t = %o\n", buf.st_nlink);
	printf("Proprietaire		-> st_uid = %o\n", buf.st_uid);
	user = getpwuid(buf.st_uid);
	printf("Nom du proprio = %s\n\n", user->pw_name);
	printf("Pass = %s\n", user->pw_passwd);
	printf("Proprietaire		-> st_gid = %o\n", buf.st_gid);
	groupe = getgrgid(buf.st_gid);
	printf("Nom du group = %s\n\n", groupe->gr_name);
	printf("taille			-> st_size = %llo\n", buf.st_size);
	(*ret)->user = &mystat.st_uid;
	user = getpwuid(*(*ret)->user);
	printf("Le fichier %s est a %s\n", (*ret)->name, user->pw_name);
*/
