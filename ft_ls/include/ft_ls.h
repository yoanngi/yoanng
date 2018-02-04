/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 14:57:20 by yoginet     ###    #+. /#+    ###.fr     */
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

/*
**	---------->	Prototypes des structures
*/
typedef	struct		s_lst
{
	char			*name;
	char			*path;
	int				access;
	struct	s_lst	*otherfile;
	struct	s_lst	*next;
}					t_lst;

typedef struct		s_struct
{
	char			*argv;
	int				argc;
	int				tiret;
	int				rmaj;
	int				rmin;
	int				amin;
	int				tmin;
	int				lmin;
	char			*file;
	char			*invalid;
	t_lst			*liste;
}					s_struct;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

/*
**	---------->	Prototypes des fonctions
**
**	Fonction general
*/
void				ft_ls(char **params, int nb);
t_lst				*ft_lstnew_ls(void);
void				ft_swap_lst(t_lst **s1, t_lst **s2);
/*
**	Fonction d'erreurs
*/
void				ft_error(s_struct *data, int i);
int					ft_check_error(char *file);
/*
**	Fonction de check des options
*/
void				ft_check_options(s_struct *data);
t_lst				*ft_ls_r(s_struct *data);

/*
**	Fonction d'affichage
*/
void				ft_ls_simple(char *target);
void				ft_print_ls(s_struct *data);
void				ft_print_ls_liste(s_struct *data);

#endif
