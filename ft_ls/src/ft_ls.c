/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:53:31 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:45:24 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_is_option_valid(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == ' ' || str[i] == 'R' || str[i] == 'r' ||
	str[i] == 'l' || str[i] == 't' || str[i] == 'a')
		{
			i++;
		}
		printf("str = %s| i = %d, lenstr = %zu\n", str, i, ft_strlen(str));
	if ((size_t)i != ft_strlen(str))
		return (0);
	return (1);
}

static void		ft_valid_or_not(char *cmp, s_struct **data)
{
	int i;

	i = 0;
	while (cmp[i])
	{
		if (cmp[i] == '-')
			(*data)->tiret = 1;
		else if (cmp[i] == 'R')
			(*data)->rmaj = 1;
		else if (cmp[i] == 'r')
			(*data)->rmin = 1;
		else if (cmp[i] == 'a')
			(*data)->amin = 1;
		else if (cmp[i] == 't')
			(*data)->tmin = 1;
		else if (cmp[i] == 'l')
			(*data)->lmin = 1;
		else
			(*data)->invalid = ft_strdup(cmp);
		i++;
	}
}

static int		ft_count_files_valid(int argc, char **argv)
{
	char	*cpy;
	int		i;
	int		nb;
	int		tmp;

	i = 0;
	nb = 0;
	tmp = argc;
	while (i != (argc - 1))
	{
		cpy = ft_strdup(argv[tmp - 1]);
		if (ft_file_exist(cpy) == 1)
			nb += 1;
		ft_strdel(&cpy);
		i++;
		tmp--;
	}
	return (nb);
}

void			ft_ls(char **params, int nb)
{
	s_struct	*data;
	int			i;
	int			dir;
	int			end;

	data = (s_struct *)malloc(sizeof(s_struct));
	i = 1;
	dir = 0;
	end = 0;
	data->nb_file = ft_count_files_valid(nb, params);
	data->multifile = (char **)malloc(sizeof(char *) * data->nb_file);
	data->invalid = NULL;
	if (!data->multifile)
		return ;
	while (i != nb)
	{
		printf("tour de boucle\n");
		if (ft_is_option_valid(params[i]) == 1 && end == 0)
		{
			printf("Options is valid = %s\n", params[i]);
			ft_valid_or_not(params[i], &data);
			if (data->invalid != NULL)
			{
				printf("data->invalid = %s\n", data->invalid);
				ft_error(data->invalid, 2);
			}
		}
		else if (ft_file_exist(params[i]) == 1)
		{
			end = 1;
			data->multifile[dir] = ft_strdup(params[i]);
			data->multifile[dir] = ft_strjoin(data->multifile[dir], "/");
			printf("data->multifile[%d] = %s\n", dir, data->multifile[dir]);
			dir++;
		}
		else
		{
			printf("***********************error\n");
			ft_error(params[i], 1);
		}
		i++;
	}
	printf("End parse arg, ft_check_options\n");
	ft_check_options(data);
}
// Not good !
// Parsing = ./ft_ls (options) (files) (options non compter) (otherfile...)
