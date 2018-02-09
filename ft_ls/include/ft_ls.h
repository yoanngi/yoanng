/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 11:38:03 by yoginet     ###    #+. /#+    ###.fr     */
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
	char			*user;
	char			*groupe;
	char			*date;
	char			*month;
	char			*day;
	char			*time;
	char			*droit;
	int				size;
	int				link;
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
	int				nb_file;
	char			*file;
	char			**multifile;
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
t_lst				*ft_class_print(t_lst **data);
char				*ft_one_argv(int nb, char **argv);
char				**ft_multi_argv(int nb, char **argv, int count);
char				**ft_add_option(int argc, char **params, int param_valid);
int					ft_file_exist(char *file_ornot);
/*
**	Fonction d'erreurs
*/
void				ft_error(char *file, int i);
int					ft_check_permissions(char *path, t_lst **rep);
/*
**	Fonction de check des options
*/
void				ft_check_options(s_struct *data);
t_lst				*ft_ls_r(s_struct *data, int indexfile);
t_lst				*ft_ls_l(s_struct *data, int indexfile);
t_lst				*ft_class_print_t(t_lst **data);
/*
**	Recuperation d'infos
*/
char				*ft_get_user(char **path);
char				*ft_get_groupe(char **path);
char				*ft_get_time(char **path);
char				*ft_get_droit(char **path);
int					ft_get_size(char **path);
int					ft_get_link(char **path);
char				*ft_return_time(char *str);
char				*ft_return_month(char *str);
char				*ft_return_day(char *str);
int					ft_checklongmax_link(t_lst **data);
int					ft_checklongmax_size(t_lst **data);
/*
**	Fonction d'affichage
*/
void				ft_ls_simple(char *target);
void				ft_ls_liste(t_lst **data, int secret);
void				ft_print_ls(s_struct *data, int indexfile);
void				ft_print_ls_liste(s_struct *data, int indexfile);

#endif
