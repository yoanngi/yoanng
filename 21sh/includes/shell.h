/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 14:43:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/11 11:08:00 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
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
**	A Faire :
**	Si variable path suprimer, ne pas lancer de commande (sauf si chemin indiquer)
**	gestion des cotes et doubles code pour setenv et unsetenv
**
*/


/*
**	***	Structures ***
**
**	t_cmd -> liste chainer des commandes a executer
*/
typedef struct		s_cmd
{
	char			*rep;
	char			**tab_cmd;
	char			**env;
	struct s_cmd	*next;
}					t_cmd;
/*
**	t_struct -> On la ballade partout
*/
typedef struct		s_struct
{
	char			*path;
	char			*pwd;
	char			*oldpwd;
	char			*home;
	char			*charfound;
	char			*current_path;
	char			*prompt;
	char			*prompt_current;
	char			**tab_path;
	char			**env;
	char			**builtins;
	int				option_echo;
	int				option_i_env;
	char			**env_tmp;
	char			*char_echo;
	int				pipe;
	int				redirection;
	t_cmd			*commandes;
}					t_struct;
/*
**	***	Fonctions ***
**
**	CORE
*/
void				core_shell(char **line, t_struct *data);
int					execute_commandes(t_struct *data);
int					exec_pipe(t_struct *data);
int					exec_pipe_suite(t_struct *data);
int					ft_process(t_struct *data);
/*
**	PARSING
*/
t_cmd				*ft_split_commandes(char **line, t_struct **data);
/*
**	BUILTINS
*/
int					ft_builtins(char **line, t_struct *data);
int					func_cd(char **line, t_struct *data);
int					ft_error_cd(char *line);
void				ft_check_error_cd(t_struct **data);
int					func_echo(char **line, t_struct *data);
void				option_echo(int j, t_struct *data);
int					ft_search_env(char *str, int i, t_struct *data, int i2);
void				ft_print_echo(char *str, t_struct *data, size_t len);
int					ft_print_special(char *str, int i, int len);
char				**func_setenv(char **line, t_struct *data);
char				**func_unsetenv(char **line, t_struct *data);
void				func_env(char **line, t_struct *data);
void				print_full_env(t_struct *data);
void				ft_print_usage(char *str);
char				*ft_return_env(char *str, t_struct *data);
int					ft_option_i(char *str);
int					ft_env_cmd(t_struct *data, char **tmp, int i, int x);
int					ft_env_rep(t_struct *data, char **tmp, int i);
/*
**	INIT
*/
t_struct			*init_struct(char **env);
char				*ft_check_infos(char **env, char *find);
char				**ft_initialise_builtins(void);
void				ft_delete_struct(t_struct *data);
t_cmd				*clear_commandes(t_cmd *start);
t_cmd				*ft_init_commandes(void);
/*
**	LIB_SHELL
*/
char				**ft_del_tab(char **tab);
int					ft_len_tab(char **tab);
char				**ft_duplicate_tab(char **tab);
char				**ft_insert_in_tab(char **tab, char *str);
void				ft_print_tab(char **tab);
char				**ft_del_tab_index(char **tab, int max);
char				*ft_add_line(char *str, char **add, t_struct *data);
int					ft_dir_exist(char *path);
void				ft_display(t_struct *data);
int					ft_access(char *path);
void				basic_error(char *name, char *cmd);
int					ft_error(int cmd, char **line);
void				ft_error_dir(char *name, char *pre);
void				ft_error_unset(char *str, int what);
void				ft_error_fork(int father);
void				ft_check_path(t_struct *data, char **path);
int					good_path(char *target, char *cmd, int opt);
char				*ft_return_path(char *str);
int					ft_insert_tild(t_struct *data, char **str, int i);
int					ft_insert_dollar(t_struct *data, char **str, int i);
int					ft_existe_in_path(t_struct *data, char **path);
char				*ft_return_pwd(void);
void				ft_check_line(t_struct *data, char **line, int i);

/*
**	END
*/
#endif
