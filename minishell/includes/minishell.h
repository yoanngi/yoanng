/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:59:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/15 11:22:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
**	***	Structures ***
*/
typedef struct		s_struct
{
	char			*path;
	char			**tab_path;
	char			*pwd;
}					t_struct;

/*
**	***	Fonctions ***
*/

/*
**	ft_error.c
*/
void				basic_error(char *name);
int					ft_error(int cmd, char **line);
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
#endif
