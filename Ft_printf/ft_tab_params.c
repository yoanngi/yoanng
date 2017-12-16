/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab_params.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 13:36:58 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 14:31:29 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_tab(s_struct *ma_struct, int index, int compt)
{
	char	**tab;

	tab = NULL;
	if (ma_struct->argv == NULL)
	{
		if (tab = (char **)malloc(sizeof(char) * (ma_struct->argc + 1)) == NULL)
			return (NULL);
	}
	tab[compt] = ft_strsub(ma_struct->s, index, 2);
	return (tab);
}

s_struct		*ft_tab_params(s_struct *ma_struct, int i)
{
	int		nb_params;
	int		index;
	int		compt;
	char	*cpy;
	char	c;

	c = "sSpdDioOuUxXcC"
	nb_params = ma_struct->argc;
	index = 0;
	compt = 0;
	cpy = ft_strdup(ma_struct->s);
	while (cpy[index])
	{
		i = 0;
		while (c[i])
		{
			if (cpy[index] == '%' && cpy[index + 1] == c)
			{
				ma_struct->argv = ft_tab(ma_struct, index, compt);
				compt++;
			}
			i++;
		}
		index++;
	}

	return (ma_struct);
}
