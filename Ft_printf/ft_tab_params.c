/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 13:36:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 14:45:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		**ft_tab_argv(s_struct *ma_struct, int i)
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
		while (cpy[len] != ' ')
			len++;
		tab[compt] = ft_strsub(cpy, i, (len - i + 1));
		i = len;
		compt++;
	}
	ft_strdel(&cpy);
	return (tab);
}

char		**ft_tab_params(s_struct *ma_struct)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (ma_struct->argc + 1))))
		return (NULL);
	return (tab);
}
