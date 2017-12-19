/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 16:32:41 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 13:42:35 by yoginet     ###    #+. /#+    ###.fr     */
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
**									-> ft_tab_argv
**									-> Si pas de parametres, on print *format.
**	Etape 2 :	ft_tab_argv  (Si plusieurs arguments)
**				Permets de creer un tableau avec les "regex" des parametres
**				Stock de % jusau'au premier espace.
**				Les parametres sont stocker dans l'ordre.
**	Etape 3 :	ft_printf (si plusieurs arguments)
**				On stock les valeurs des params dans un tableau de void
**	Etape 4 :	ft_printargv.
**
*/

/*
** Prototypes des structures
*/
typedef struct		s_struct
{
	int		argc;
	char	*s;
	char	**argv;
	void	**params;
}					s_struct;

/*
** Prototypes des fonctions
*/
void				ft_print_line_final(s_struct *data);
char				**ft_tab_argv(s_struct *ma_struct, int i);
char				**ft_delete_one_colun(char **tab, int len);
char				*ft_insert_word(char *new, s_struct *data, int index, char *word);
int					ft_printf(const char *format, ...);
int					ft_printfargv(s_struct *data, int i);

#endif
