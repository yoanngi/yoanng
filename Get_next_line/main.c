/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 10:30:22 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 11:38:15 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		ret;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		line = NULL;
		if (fd)
		{
			printf("Ouverture ok\n");
			while ((ret = get_next_line(fd, &line)) == 1)
			{
				printf("ret = |%d| Line (%d) = |%s|\n", ret, i, line);
				i++;
			}
			printf("ret = |%d|", ret);
			close(fd);
			printf("\nFermeture ok\n");
		}
	}
	return (0);
}
