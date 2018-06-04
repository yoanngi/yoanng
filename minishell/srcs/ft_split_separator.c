/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_separator.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 15:26:03 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 15:50:11 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		**ft_separator_complex(char *str, int valid, int x, int no)
{
	char		**tab;
	int			i;
	int			j;

	tab = (char **)malloc(sizeof(char *) * (valid + 1));
	i = 0;
	j = 0;
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && no == 0)
			no = 1;
		else if ((str[i] == '\'' || str[i] == '\"') && no == 1)
			no = 0;
		else if (str[i] == ';' && no == 0)
		{
			tab[j] = ft_strsub(str, x, i);
			j++;
			x = i;
		}
		i++;
	}
	tab[valid] = NULL;
	return (tab);
}

static int		ft_count_separator_valid(char *str)
{
	int		i;
	int		j;
	int		no;

	i = 0;
	j = 0;
	no = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && no == 0)
			no = 1;
		else if ((str[i] == '\'' || str[i] == '\"') && no == 1)
			no = 0;
		else if (str[i] == ';' && no == 0)
			j++;
		i++;
	}
	return (j);
}

static int		ft_count_separator(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ';')
			j++;
		i++;
	}
	return (j);
}

char			**ft_split_separator(char **line)
{
	char	**tab;
	int		separator;
	int		valid;

	tab = NULL;
	separator = ft_count_separator(*line);
	valid = 0;
	if (separator == 0)
		tab = ft_strsplit(*line, ';');
	else
	{
		if ((valid = ft_count_separator_valid(*line)) == separator)
			tab = ft_strsplit(*line, ';');
		else
			tab = ft_separator_complex(*line, valid, 0, 0);
	}
	return (tab);
}
