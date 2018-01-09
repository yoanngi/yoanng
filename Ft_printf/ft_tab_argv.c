/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_argv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 08:44:59 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 11:55:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Man ft_tab_argv
**	Retourne un tableau qui a split notre chaine (format) de '%' au
**	prochain '%' ou fin de chaine.
*/

static int	ft_long(char *cpy, int i)
{
	int compt;
	int j;

	compt = 0;
	j = i;
	while (cpy[i])
	{
		i++;
		compt++;
		if(cpy[i] == '%' && cpy[i + 1] != '%')
			return (compt);
	}
	return (ft_strlen(cpy) - j);
}

char		**ft_tab_argv(s_struct *ma_struct, int i, int len)
{
	int		compt;
	char	*cpy;
	char	**tab;

	compt = 0;
	cpy = ft_strdup(ma_struct->s);
	if (!(tab = (char **)malloc(sizeof(char *) * (ma_struct->argc + 1))))
		return (NULL);
	while (compt != ma_struct->argc)
	{
		while (cpy[i] != '\0')
		{
			if (cpy[i] == '%')
				break ;
			i++;
		}
		len = ft_long(cpy, i);
		tab[compt] = ft_strsub(cpy, i, len);
		i += len;
		compt++;
	}
	ft_strdel(&cpy);
	ft_valid_argv(tab, ma_struct);
	return (tab);
}
