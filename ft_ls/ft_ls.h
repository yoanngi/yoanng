/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:28:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 11:18:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <dirent.h>
# include <sys/types.h>

typedef struct		s_struct
{
	char	*argv;
	int		tiret;
	int		rmaj;
	int		rmin;
	int		amin;
	int		tmin;
	int		lmin;
}					s_struct;

/*
** Prototypes des fonctions
*/

void				ft_ls(int argc, char **argv);

#endif
