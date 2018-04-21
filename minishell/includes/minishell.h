/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:59:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 11:47:07 by yoginet     ###    #+. /#+    ###.fr     */
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
**	***	Structures ***
*/
typedef struct		s_struct
{
	char			*path;
	char			*prompt;
	char			*prompt_current;
	char			**tab_path;
	char			**env;
	char			*pwd;
	char			*home;
	char			*current_path;
	char			*charfound;
}					t_struct;

/*
**	***	Fonctions ***
*/

/*
**	minishell.c
*/
int					ft_minishell(char **line, t_struct *data);
/*
**	func_spe.c
*/
int					func_spe(char **line, char **line_2, t_struct *data);
/*
**	ft_error.c && func_access.c
*/
void				basic_error(char *name);
int					ft_error(int cmd, char **line);
void				ft_error_dir(char *name, char *pre);
int					ft_access(char *path);
/*
**	ft_cmd_annexe.c
*/
int					ft_cmd_annexe(char **line, t_struct *data);
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
**	func.c
*/
char				*ft_del_tab(char **tab);
char				*ft_add_line(char *str, char *add);
int					ft_len_tab(char **tab);
int					ft_dir_exist(char *path);
int					ft_search_cd(char *str, char c, char d);
/*
**	func_cd.c
**	func_echo.c
**	func_setenv.c
**	func_unsetenv.c
**	func_env.c
**	func_exit.c
*/
int					func_cd(char **line, t_struct *data);
int					func_echo(char **line, t_struct *data);
char				**func_setenv(char **line, t_struct *data);
char				**func_unsetenv(char **line, t_struct *data);
void				func_env(char **line, t_struct *data);
void				func_exit(char **line, t_struct *data);
#endif
