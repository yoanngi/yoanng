/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 09:27:00 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 11:07:19 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**params;

	i = 1;
	j = 0;
	if ((params = (char **)malloc(sizeof(char *) * (argc + 1))) == NULL)
		return (-1);
	if (argc > 1)
	{
		while (i != argc)
		{
			params[j] = ft_strdup(argv[i]);
			i++;
			j++;
		}
		ft_ls(params, argc);
	}
	else
		ft_putstr("ls simple\n");
	return (0);
}
