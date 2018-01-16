/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 16:32:41 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 13:32:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
**	Manuel ft_printf
**	Etape 1 :	ft_insert_params	-> Stock le nb d'arguments dans argc
**									-> Stock format dans s
**									-> ft_tab_argv
**									-> Si pas de parametres, on print *format.
**	Etape 2 :	ft_tab_argv  (Si plusieurs arguments)
**				Permets de creer un tableau avec les "regex" des parametres
**				Stock de % jusau'au suivant %.
**				Les parametres sont stocker dans l'ordre.
**	Etape 3 :	ft_printf (si plusieurs arguments)
**				On stock les valeurs des params dans un tableau de void
**	Etape 4 :	ft_printargv.
**
**
**
** Prototypes des structures
*/

typedef struct		s_struct
{
	void	**params;
	int		argc;
	int		flag;
	int		flag_plus;		// Flag
	int		flag_moins;
	int		flag_diese;
	int		flag_space;
	int		pre_befor;		// Presision (. ou *)
	int		pre_behind;
	int		point;
	char	conversion;		// Code de conversion (d, i, o u x X f e E)
	char	modificateur;	// Parametre modificateur (h l L)
	char	*s;
	char	*s_final;
	char	**argv;
	char	**no_valid;
}					s_struct;

/*
** Prototypes des fonctions
*/
int					ft_printf(const char *format, ...);

void				ft_print_line_final(s_struct *data);
char				**ft_tab_argv(s_struct *ma_struct, int i, int x);
char				**ft_delete_one_colun(char **tab, int len);
char				*ft_insert_word(s_struct *data, int index, int i);
char				*ft_delete_word(char *data, int index, int len);
void				ft_valid_argv(char **tab, s_struct *data);
int					ft_printfargv(s_struct *data, int i);
char				**ft_size_tab(int nb);
int					ft_analyse_flag(s_struct *data, int i);

#endif
