/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 10:53:10 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 14:40:11 by yoginet          ###   ########.fr       */
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

    i = 0;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        line = NULL;
        if (fd)
        {
            printf("Ouverture ok\n");
            while ((i = get_next_line(fd, &line)) == 1)
            {
                printf("Valeur de i = |%d|\n", i);
                printf("Line = |%s|\n", line);
                free(line);
                line = NULL;
            }
            close(fd);
            printf("Fermeture ok\n");
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
