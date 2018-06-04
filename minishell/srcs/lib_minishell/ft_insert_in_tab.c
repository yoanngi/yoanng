/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_insert_in_tab.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 11:33:43 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 11:34:50 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Insert str in tab and return
*/

static char		**ft_insert_suite(char *str)
{
	char	**new;

	new = NULL;
	if (!(new = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	new[0] = ft_strdup(str);
	new[1] = NULL;
	return (new);
}

char			**ft_insert_in_tab(char **tab, char *str)
{
	char	**new;
	int		len;
	int		i;

	new = NULL;
	i = 0;
	if (tab != NULL)
	{
		len = ft_len_tab(tab);
		if (!(new = (char **)malloc(sizeof(char *) * (len + 2))))
			return (NULL);
		while (tab[i])
		{
			new[i] = ft_strdup(tab[i]);
			i++;
		}
		new[len] = ft_strdup(str);
		new[len + 1] = NULL;
	}
	else
		new = ft_insert_suite(str);
	return (new);
}
