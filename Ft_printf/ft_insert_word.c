/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_insert_word.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 09:35:47 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 10:53:18 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Fonction qui insert un mot dans une phrase
**	new = chaine vide de la bonne taille
**	data->s = string = chaine ou il faut insert le mot
**	index = emplacement du mot a inserer
**	word = mot a inserer
*/

char	*ft_insert_word(s_struct *data, int index, int i)
{
	char	*new;
	char	*tmp;
	int		len;
	int		j;

	j = 0;
	tmp = ft_strdup(data->params[i]);
	len = ft_strlen(data->s) + ft_strlen(data->params[i]);
	new = ft_strnew(len - ft_strlen(data->argv[i]) + 1);
	ft_strncpy(new, data->s, index);
	j = 0;
	while (tmp[j])
	{
		new[index] = tmp[j];
		j++;
		index++;
	}
	j = index - ft_strlen(data->argv[i]) - 1 ;
	while (j != len)
	{
		new[index] = data->s[j];
		index++;
		j++;
	}
	new[index] = '\0';
	return (new);
}

char	*ft_delete_word(char *data, int index, int len)
{
	char	*new;
	int		j;

	new = ft_strnew(ft_strlen(data) - len);
	if (index != 0)
			ft_strncpy(new, data, index);
	j = index;
	index = index + len;
	while (data[index])
	{
		new[j] = data[index];
		index++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
