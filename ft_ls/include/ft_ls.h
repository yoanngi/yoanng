/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 13:59:43 by yoginet     ###    #+. /#+    ###.fr     */
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
	char			*path;
	struct	s_lst	*otherfile;
	struct	s_lst	*next;
}					t_lst;

typedef struct		s_struct
{
	char			*argv;
	//int				nb_options;
	int				argc;
	int				tiret;
	int				rmaj;
	t_lst			*liste;
	t_lst			*listeclean;
	int				rmin;
	int				amin;
	int				tmin;
	int				lmin;
	char			*file;
	char			*invalid;
}					s_struct;

typedef struct dirent	t_dir;

/*
** Prototypes des fonctions
*/

void				ft_ls(char **params, int nb);
void				ft_error(s_struct *data, int i);
void				ft_check_options(s_struct *data);
void				ft_ls_simple(char *target);
t_lst				*ft_lstnew_ls(void);
void				ft_print_ls(s_struct *data);

#endif
