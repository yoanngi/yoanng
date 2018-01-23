/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 11:18:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <uuid/uuid.h>

# include <stdio.h>

typedef	struct		s_lst
{
	char			*name;
	char			**params;
	int				size;
	struct	s_lst	*previous;
	struct	s_lst	*next;
}					t_lst;

typedef struct		s_struct
{
	char			*argv;
	int				nb_options;
	int				tiret;
	int				rmaj;
	int				rmin;
	int				amin;
	int				tmin;
	int				lmin;
	char			*invalid;
}					s_struct;

typedef struct dirent	t_dir;

/*
** Prototypes des fonctions
*/

void				ft_ls(char **params, int nb);
void				ft_error(s_struct *data);
void				ft_ls_simple(void);
void				ft_check_options(s_struct *data, DIR *dir);
t_lst				*ft_add_list(void);
t_lst				ft_list_add_ls(t_lst *data, t_dir *fichierlu);

#endif
