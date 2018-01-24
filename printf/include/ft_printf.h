/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 16:32:41 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 08:26:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

/*
** Prototypes des structures
*/

typedef struct		s_struct
{
	void	**params;		// Params recuperer par va_list
	int		argc;			// nb arguments
	int		nb_arg_traiter;
	int		dmodulo;		// Si double modulo
	int		simple_s;		// Si %s
	int		simple_d;		// Si %d
	int		flag_plus;		// Flag
	int		flag_moins;
	int		flag_diese;
	int		flag_space;
	int		pre_befor;		// Presision (. ou *)
	int		pre_behind;
	int		point;
	char	conversion;		// Code de conversion (d, i, o u x X f e E)
	char	modificateur;	// Parametre modificateur (h l L)
	char	*s;				// format
	char	*s_final;		// format modifier au fur et a meusure
	char	**argv;			// Tab des arguments spliter
}					s_struct;

/*
** Prototypes des fonctions
*/
int					ft_printf(const char *format, ...);
int					ft_argv_valid(char *str, int index);
char				**ft_tab_argv(s_struct *ma_struct, int i, int x);
int					ft_parse(s_struct *data);
int					ft_check_options(s_struct *data, int i);

#endif
