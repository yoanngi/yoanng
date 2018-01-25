/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:27:00 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 11:27:46 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**params;

	i = 1;
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
		ft_ls(params, argc);
	}
	return (0);
}
