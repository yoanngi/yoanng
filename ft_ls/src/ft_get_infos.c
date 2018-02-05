/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_infos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 14:25:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:53:14 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_user(t_dir **fichierlu)
{
	struct passwd	*user;
	t_stat			buf;
	char			*cpy;

	stat(((*fichierlu)->d_name), &buf);
	user = getpwuid(buf.st_uid);
	cpy = ft_strdup(user->pw_name);
	return (cpy);
}

char	*ft_get_groupe(t_dir **fichierlu)
{
	struct group	*groupe;
	t_stat			buf;
	char			*cpy;

	stat(((*fichierlu)->d_name), &buf);
	groupe = getgrgid(buf.st_gid);
	cpy = ft_strdup(groupe->gr_name);
	return (cpy);
}

char	*ft_get_time(t_dir **fichierlu)
{
	t_stat			buf;
	char			*cpy;

	stat(((*fichierlu)->d_name), &buf);
	cpy = ft_strdup(ctime(&buf.st_mtime));
	return (cpy);

}

char	*ft_get_droit(t_dir **fichierlu)
{
	t_stat			buf;
	char			*cpy;

	cpy = ft_strnew(10);
	stat(((*fichierlu)->d_name), &buf);
	// A modifier
	cpy[0] = *((S_ISDIR(buf.st_mode)) ? "d" : "-");
	cpy[0] = *((S_ISLNK(buf.st_mode)) ? "l" : "-");
	cpy[0] = *((S_ISSOCK(buf.st_mode)) ? "s" : "-");
	cpy[0] = *((S_ISBLK(buf.st_mode)) ? "b" : "-");
	cpy[0] = *((S_ISFIFO(buf.st_mode)) ? "f" : "-");
	//
	cpy[1] = *((buf.st_mode & S_IRUSR) ? "r" : "-");
	cpy[2] = *((buf.st_mode & S_IWUSR) ? "w" : "-");
	cpy[3] = *((buf.st_mode & S_IXUSR) ? "x" : "-");
	cpy[4] = *((buf.st_mode & S_IRGRP) ? "r" : "-");
	cpy[5] = *((buf.st_mode & S_IWGRP) ? "w" : "-");
	cpy[6] = *((buf.st_mode & S_IXGRP) ? "x" : "-");
	cpy[7] = *((buf.st_mode & S_IROTH) ? "r" : "-");
	cpy[8] = *((buf.st_mode & S_IWOTH) ? "w" : "-");
	cpy[9] = *((buf.st_mode & S_IXOTH) ? "x" : "-");
	cpy[10] = '\0';
	return (cpy);

}
