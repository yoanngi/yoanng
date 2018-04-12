/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 14:59:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/10 15:16:07 by yoginet     ###    #+. /#+    ###.fr     */
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
	char	*path;
}					t_struct;

/*
**	***	Fonctions ***
*/

/*
**	ft_error.c
*/
void				basic_error(char *name);
/*
**	ft_execute.c
*/
void				ft_execute(char **line, t_struct *data);

/*
**	ft_struct.c
*/
t_struct			*ft_my_struct(char **env);
void				ft_delete_struct(t_struct *data);
#endif
