/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:59:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 15:46:02 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
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
**	Leaks : valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all
**	--leak-resolution=high --show-reachable=no --gen-suppressions=yes
**	--track-origins=yes ./minishell
**
**	Test erreur : https://forum.intra.42.fr/topics/431/messages?page=1#22608
*/

/*
**	***	Structures ***
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
	char			*char_echo;
}					t_struct;

/*
**	***	Fonctions ***
*/

/*
**	core_minishell.c
**	core_minishell_suite.c
*/
int					ft_minishell(char **line, t_struct *data);
int					ft_minishell_spe(t_struct *data, char **line);
int					ft_check_command(char **line, t_struct *data, int epur);
/*
**	func_signal.c
*/
void				my_signal(int sig);
/*
**	func_spe.c
*/
int					func_spe(char **line, char **line_2, t_struct *data);
/*
**	ft_fork.c
*/
int					ft_process(char *rep, char **cmd, char **env);
/*
**	ft_enclosing.c
*/
int					ft_search_enclosing(char **str);
int					cmd_special(char *line, t_struct *data, int ret);
/*
**	format_line.c
*/
char				**epur_tab(char *line, int epur);
/*
**	BUILTINS
**	good_func.c
**	func_cd.c
**	func_echo.c
**	func_echo_suite.c
**	func_echo_print.c
**	func_setenv.c
**	func_unsetenv.c
**	func_env.c
**	func_env_print.c
*/
int					ft_builtins(char **line, t_struct *data);
int					func_cd(char **line, t_struct *data);
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
/*
**	INIT
**	ft_struct.c
*/
t_struct			*ft_my_struct(char **env);
t_struct			*ft_my_struct_null(void);
void				ft_delete_struct(t_struct *data);
char				**ft_initialise_builtins(void);
/*
**	LIB_MINISHELL
*/
char				*ft_del_tab(char **tab);
char				*ft_add_line(char *str, char **add, t_struct *data);
int					ft_len_tab(char **tab);
int					ft_dir_exist(char *path);
void				ft_display(t_struct *data);
int					ft_access(char *path);
void				basic_error(char *name, char *cmd);
int					ft_error(int cmd, char **line);
void				ft_error_dir(char *name, char *pre);
void				ft_error_unset(char *str, int what);
void				ft_error_fork(int father);
void				ft_check_path(t_struct *data, char **path);
int					good_path(char *target, char *cmd);
char				*ft_return_path(char *str);
/*
**	END
*/
#endif
