/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 13:25:33 by yoginet     ###    #+. /#+    ###.fr     */
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

// a suprimer
# include <stdio.h>

/*
**	---------->	Prototypes des structures
*/
typedef struct			s_lst
{
	char				*name;
	char				*path;
	int					access;
	char				*user;
	char				*groupe;
	time_t				date;
	char				*month;
	char				*day;
	char				*time;
	char				*droit;
	char				*symbol;
	int					size;
	int					link;
	blkcnt_t			blocks;
	struct s_lst		*otherfile;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_struct
{
	char				*argv;
	int					argc;
	int					tiret;
	int					rmaj;
	int					rmin;
	int					amin;
	int					tmin;
	int					lmin;
	int					nb_file;
	char				**multifile;
	int					invalid;
	t_lst				*liste;
}						s_struct;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

/*
**	---------->	Prototypes des fonctions
**
**	Fonction general
*/
void					ft_ls(char **params, int nb, int end);
t_lst					*ft_lstnew_ls(void);
char					*ft_one_argv(int nb, char **argv);
char					**ft_multi_argv(int nb, char **argv, int count);
char					**ft_add_option(int argc, char **params, int p_valid);
int						ft_file_exist(char *file_ornot);
int						ft_option_exist(char *str, int nb);
void					ft_insert_valid_option(char *cmp, s_struct **data);
int						ft_count_files_valid(int argc, char **argv);
/*
**	Fonction clean
*/
void					ft_clean_data(t_lst **data);
t_lst					*ft_clean_list(t_lst *data);
void					ft_clean_tmp(t_lst **tmp);
/*
**	Fonction principales
*/
t_lst					*ft_ls_r(s_struct *data, int indexfile);
t_lst					*ft_read_repertoire(t_dir **fichierlu, char *path, s_struct *structure);
/*
**	Fonction d'erreurs
*/
void					ft_error(char arg);
void					basic_error(char *error);
void					ft_error_access(char *error);
int						ft_access_or_not(char **path);
void					ft_print_error(t_lst *cpy);
/*
**	Fonction de check des options
*/
void					ft_check_options(s_struct *data);
t_lst					*ft_class_print_t(t_lst **data);
int						ft_how_to_treat(int ac, char **av, int i, s_struct **data);
void					ft_ls_two(int i, int nb, char **params, s_struct **data);
t_lst					*ft_return_access_denied(t_dir **fichierlu, char *path);
/*
**	Recuperation d'infos
*/
char					*ft_get_user(char **path);
char					*ft_get_groupe(char **path);
time_t					ft_get_time(char **path);
char					*ft_get_droit(char **path);
char					ft_get_droit_two(char **path);
char					*ft_get_droit_symbolique(char **path, size_t size);
char					*ft_get_new_path(char **path);
int						ft_get_size(char **path);
int						ft_get_link(char **path);
int						ft_get_blocks(char **path);
char					*ft_return_time(time_t str);
char					*ft_return_month(time_t str);
char					*ft_return_day(time_t str);
int						ft_checklongmax_link(t_lst **data);
int						ft_checklongmax_size(t_lst **data);
int						ft_checklongmax_user(t_lst **data);
int						ft_checklongmax_group(t_lst **data);
/*
**	Fonction de trie
*/
t_lst					*what_sort(s_struct *data, t_lst *liste);
t_lst					*ft_reverse_lst(t_lst *prime);
t_lst					*lst_sort_ascii(t_lst *lst);
t_lst					*lst_sort_time(t_lst *lst);
t_lst					*lst_swap(t_lst *lst1, t_lst *lst2);
/*
**	Fonction d'affichage
*/
void					ft_resize_path(char *str);
void					ft_print_blocks(t_lst **liste);
void					ft_ls_simple(char *target, int a);
void					ft_ls_liste(t_lst **data, int secret);
void					ft_print_ls(s_struct *data);
void					ft_print_ls_liste(s_struct *data);
void					ft_print_liste(t_lst *recur, s_struct *data);
int						ft_print_block_or_not(t_lst **data, int secret);

#endif
