/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_argv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 08:44:59 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 10:44:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Man ft_tab_argv
**	Retourne un tableau qui a split notre chaine (format) de '%' au
**	prochain '%' ou fin de chaine.
*/

char		**ft_tab_argv(s_struct *ma_struct, int i, int x)
{
	int		len;
	int		compt;
	char	*cpy;
	char	**tab;

	compt = 0;
	cpy = ft_strdup(ma_struct->s);
	if (!(tab = (char **)malloc(sizeof(char *) * (ma_struct->argc + 1))))
		return (NULL);
	while (compt != ma_struct->argc)
	{
		while (cpy[i] != '%')
			i++;
		len = i;
		i = i + 1;
		while (cpy[i] != '%' && x == 1)
		{
			x = (size_t)i == ft_strlen(cpy) ? 0 : 1;
			i++;
		}
		tab[compt] = ft_strsub(cpy, len, (i - len - x));
		compt++;
	}
	ft_strdel(&cpy);
	return (tab);
}
