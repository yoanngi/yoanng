/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 16:32:41 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 14:31:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>

/*
**	Manuel ft_printf
**	Etape 1 :	ft_insert_params	-> Stock le nb d'arguments dans argc
**									-> Stock format dans s
**									-> Si pas de parametres, on print *fomat.
**	Etape 2 :	ft_tab_params (Si plusieurs arguments)
**				Permets de creer un tableau avec les valeurs des parametres
**				Les parametres sont stocker dans l'ordre.
**	Etape 3 :	ft_printfargv
*/

/*
** Prototypes des structures
*/
typedef struct		s_struct
{
	char	*s;
	int		argc;
	char	**argv;
}					s_struct;

/*
** Prototypes des fonctions
*/

s_struct	*ft_tab_params(s_struct *ma_struct, int i);
int			ft_printf(const char *format, ...);
int			ft_printfargv(s_struct *data, char **tab);

#endif
