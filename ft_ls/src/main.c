/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:27:00 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 13:30:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**params;
	int		dir;
	int		end;

	i = 1;
	dir = 0;
	end = 0;
	if (argc == 1)
		ft_ls_simple((char *)".");
	else if (argc > 1)
	{
		if ((params = (char **)malloc(sizeof(char *) * (argc + 1))) == NULL)
			return (-1);
		while (i != argc)
		{
			params[i] = ft_strdup(argv[i]);
			i++;
		}
		ft_ls(params, argc, dir, end);
	}
	return (0);
}
