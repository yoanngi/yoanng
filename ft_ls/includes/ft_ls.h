/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:41:46 by yoginet     ###    #+. /#+    ###.fr     */
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
**	0 Leaks :
**	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all
**	--leak-resolution=high --show-reachable=no --gen-suppressions=yes
**	--track-origins=yes ./ft_ls $1 $2 $3
*/

/*
**	---------->	Prototypes des structures
*/
typedef struct			s_lst
{
	char				*name;
	char				*path;
	char				*user;
	char				*groupe;
	char				*droit;
	char				*symbol;
	int					access;
	int					size;
	int					minor;
	int					major;
	int					link;
	time_t				date;
	blkcnt_t			blocks;
	struct s_lst		*otherfile;
	struct s_lst		*denied;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_rep
{
	char				*name;
	time_t				date;
	struct s_rep		*next;
}						t_rep;

typedef struct			s_struct
{
	int					argc;
	int					tiret;
	int					rmaj;
	int					rmin;
	int					amin;
	int					tmin;
	int					lmin;
	int					un;
	int					omin;
	int					nb_file;
	int					just_file;
	int					invalid;
	t_rep				*multifile;
	t_rep				*filevalid;
	t_lst				*liste;
}						t_struct;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

/*
**	---------->	Prototypes des fonctions
**
**	Fonction general
*/
void					ft_ls(char **params, int nb, int end);
t_lst					*ft_lstnew_ls(void);
t_rep					*ft_lstnew_argv(void);
char					*ft_one_argv(int nb, char **argv);
char					**ft_multi_argv(int nb, char **argv, int count);
char					**ft_add_option(int argc, char **params, int p_valid);
int						ft_option_exist(char *str, int nb);
void					ft_insert_valid_option(char *cmp, t_struct **data);
char					**ft_range_tab(char **tab, int len, int i);
int						ft_is_file(char **path);
/*
**	Fonction clean
*/
t_lst					*ft_clean_list(t_lst **data);
t_rep					*ft_clean_t_dir(t_rep **data);
void					ft_del_infos(t_lst **liste);
t_struct				*ft_del_struct(t_struct *data);
/*
**	Fonction principales
*/
t_lst					*ft_ls_r(t_struct *data, char *file);
t_lst					*ft_insert_datas(t_dir **fd, t_lst **ret, char *path);
t_lst					*ft_r_repertory(t_dir **fd, char *path, t_struct *st);
void					ft_insert_path(t_dir *fd, t_lst **data, char *path);
/*
**	Fonction d'erreurs
*/
void					ft_error(char arg);
void					basic_error(char *error);
t_lst					*ft_print_error(t_lst *cpy, int amin);
/*
**	Fonction de check des options
*/
int						ft_access_or_not(char **path);
int						ft_access_or_not_start(char **path);
void					ft_check_options(t_struct *data);
t_rep					*ft_dir_valid(int i, int nb, char **params);
t_rep					*ft_file_valid(int i, int nb, char **params);
void					ft_error_argv(int i, int nb, char **tab, t_struct *da);
t_lst					*ft_return_access_denied(t_dir **fichierlu, char *path);
/*
**	Recuperation d'infos
*/
char					*ft_get_user(t_stat buf);
char					*ft_get_groupe(t_stat buf);
time_t					ft_get_time(t_stat buf);
char					*ft_get_droit(t_stat buf);
char					ft_get_droit_two(t_stat buf);
char					*ft_get_droit_symbolique(char **path, size_t size);
char					*ft_get_new_path(char **path);
void					ft_minmajorsize(t_stat buf, t_lst **ret);
int						ft_get_size(t_stat buf);
int						ft_get_minor(t_stat buf);
int						ft_get_major(t_stat buf);
int						ft_get_link(t_stat buf);
int						ft_get_blocks(t_stat buf);
void					ft_return_time(time_t str);
void					ft_return_month(time_t str);
void					ft_return_day(time_t str);
int						ft_checklongmax_link(t_lst **data);
int						ft_checklongmax_size(t_lst **data);
int						ft_checklongmax_user(t_lst **data);
int						ft_checklongmax_group(t_lst **data);
int						ft_checklongmax_minor(t_lst **data);
int						ft_checklongmax_major(t_lst **data);
/*
**	Fonction de trie
*/
t_lst					*what_sort(t_struct *data, t_lst *liste);
t_lst					*ft_reverse_lst(t_lst *prime);
t_lst					*lst_sort_ascii(t_lst *lst);
t_lst					*lst_sort_ascii_inv(t_lst *lst);
t_lst					*lst_sort_time(t_lst *lst);
void					ft_swap_lst(t_lst **s1, t_lst **s2);
void					ft_swap_data(t_lst **s1, t_lst *s2);
void					ft_class_repertory(t_rep **lst, t_struct *data);
/*
**	Fonction d'affichage
*/
void					ft_resize_path(char *str);
void					ft_print_blocks(t_lst **liste, int amin);
int						ft_print_block_or_not(t_lst **data, int secret);
void					ft_ls_simple(char *target, int a);
void					ft_ls_liste(t_lst **data, int secret, int omin);
void					ft_print_ls(t_struct *data);
void					ft_print_ls_liste(t_struct *data);
t_lst					*ft_print_liste(t_lst *recur, t_struct *data);
void					ft_display_one(t_lst **da, int link, int use);
void					ft_display_two(t_lst **data, int size, int mi, int ma);
void					ft_print_file(char **path, t_struct *data, t_lst **ret);
void					ft_display_grp(int grp, t_lst **da);
void					ft_ls_simple_sort(t_lst *lst, int amin);

#endif
