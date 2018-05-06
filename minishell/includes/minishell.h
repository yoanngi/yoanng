/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:59:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 10:35:45 by yoginet     ###    #+. /#+    ###.fr     */
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
*/

/*
**	***	Structures ***
*/
typedef struct		s_struct
{
	char			*path;
	char			*pwd;
	char			*home;
	char			*charfound;
	char			*current_path;
	char			*prompt;
	char			*prompt_current;
	char			**tab_path;
	char			**env;
	char			**builtins;
}					t_struct;

/*
**	***	Fonctions ***
*/

/*
**	minishell.c
*/
int					ft_minishell(char **line, t_struct *data);
/*
**	func_signal.c
*/
void				monsignal(int sig);
/*
**	func_spe.c
*/
int					func_spe(char **line, char **line_2, t_struct *data);
/*
**	ft_error.c && func_access.c
*/
void				basic_error(char *name, char *cmd);
int					ft_error(int cmd, char **line);
void				ft_error_dir(char *name, char *pre);
void				ft_error_unset(char *str, int what);
int					ft_access(char *path);
/*
**	ft_struct.c
*/
t_struct			*ft_my_struct(char **env);
void				ft_delete_struct(t_struct *data);
/*
**	ft_fork.c
*/
int					ft_process(char *rep, char **cmd);
/*
**	various_func.c
*/
char				*ft_del_tab(char **tab);
char				*ft_add_line(char *str, char *add);
int					ft_len_tab(char **tab);
int					ft_dir_exist(char *path);
/*
**	ft_enclosing.c
*/
int					ft_search_enclosing(char **str);
/*
**	format_line.c
*/
char				**epur_tab(char *line, int epur);
/*
**	good_func.c
*/
int					ft_cmd_annexe(char **line, t_struct *data);

/*
**	func_cd.c
**	func_echo.c
**	func_echo_suite.c
**	func_setenv.c
**	func_unsetenv.c
**	func_env.c
*/
int					func_cd(char **line, t_struct *data);
int					func_echo(char **line, t_struct *data);
void	 		   	echo_clear_string_simple(char *str);
void	    		echo_clear_special(char **str);
void	    		echo_env(char *str, t_struct *data);
char				**func_setenv(char **line, t_struct *data);
char				**func_unsetenv(char **line, t_struct *data);
void				func_env(char **line, t_struct *data);
#endif
