/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_file.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:20:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:37:37 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_one_argv(int nb, char **argv)
{
	int		i;
	char	*cpy;

	i = nb;
	while (i--)
	{
		cpy = ft_strdup(argv[i - 1]);
		if (ft_file_exist(cpy) == 1)
			return (cpy);
		else
			ft_error(cpy, 2);
		ft_strdel(&cpy);
	}
	return (NULL);
}

char	**ft_multi_argv(int nb, char **argv, int i)
{
	char	**tab;
	char	*cpy;
	int		j;
	int		nb2;

	j = 0;
	nb2 = nb;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	while (nb2 != 2)
	{
		cpy = ft_strdup(argv[nb2 - 1]);
		if (ft_file_exist(cpy) == 1)
		{
			tab[j] = ft_strdup(cpy);
			j++;
		}
		ft_strdel(&cpy);
		nb2--;
	}
	tab[j][0] = '\0';
	return (tab);
}

char	**ft_add_option(int argc, char **params, int param_valid)
{
	char	**tab;
	char	*cpy;
	int		nb2;
	int		i;

	nb2 = argc;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (argc - param_valid));
	if (!tab)
		return (NULL);
	while (nb2 != 2)
	{
		cpy = ft_strdup(argv[nb2 - 1]);
		if (ft_file_exist(cpy) == 0)
		{
			tab[i] = ft_strdup(cpy);
			i++;
		}
		ft_strdel(&cpy);
		nb2--;
	}
	tab[i][0] = '\0';
	return (tab);
}

int		ft_file_exist(char *file_ornot)
{
	DIR		*dir;

	if ((dir = opendir(file_ornot)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}
