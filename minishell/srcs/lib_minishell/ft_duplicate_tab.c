/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_duplicate_tab.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 11:24:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 11:25:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Duplicate tab and return tab
*/

char		**ft_duplicate_tab(char **tab)
{
	char	**new;
	int		len;
	int		i;

	new = NULL;
	if (tab == NULL)
		return (NULL);
	len = ft_len_tab(tab);
	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[len] = NULL;
	return (new);
}
