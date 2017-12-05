/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 10:30:22 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 16:34:59 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		line = NULL;
		if (fd)
		{
			printf("Ouverture ok\n\n\n");
			while (get_next_line(fd, &line) == 1)
			{
				printf("Line = |%s|\n", line);
			}
			close(fd);
			printf("\n\n\nFermeture ok\n");
		}
		if (fd == -1)
		{
			printf("Error read documents\n");
			return (1);
		}
	}
	else
		printf("usage : ./a.out <target file>\n");
	return (0);
}
