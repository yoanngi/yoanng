/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hash_path.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 13:59:22 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 14:02:27 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  Source : http://www.cse.yorku.ca/~oz/hash.html (adapter)
**  Taux de collisions : 281 / 1346
*/

long           ft_calcul_hash(char *str, int sizemax)
{
    int     i;
    long    hash;

    i = 0;
    hash = 0;
    while ((i = *str++))
        hash = i + (hash << 6) + (hash << 16) - hash;
    if (hash < 0)
        hash *= -1;
    if (sizemax == 0)
        return (hash);
    else
    {
        while (hash > sizemax)
        {
            hash = (hash / 3) + (hash % 5);
        }
    }
    return (hash);
}

/*
**  Creation de la table :
**  On compte le nombre de fichier, on malloc la size * 3
**  On insert les hash dans la table
*/

int                     ft_create_table_hash(t_struct **data)
{
    int     count;

    count = ft_work_in_tab((*data)->tab_path, &ft_count);
    count *= 10;
    (*data)->tab_hash = create_tab(count);
    printf("TAB create (size = %d)\n", count);
    if (ft_insert_hash(count, (*data)->tab_path,
    (*data)->tab_hash, &ft_calcul_hash))
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

/*
** Allocation de la table et initialisation de celle ci
*/

long         **create_tab(int size)
{
    long    **tabl;
    int     i;

    tabl = NULL;
    i = 0;
    tabl = (long **)malloc(sizeof(long *) * size);
    if (!(tabl))
        return (0);
    while (i < size)
    {
        tabl[i] = (long *)malloc(sizeof(long) * 3);
        tabl[i][0] = 0;
        tabl[i][1] = 0;
        tabl[i][2] = 0;
        i++;
    }
    return (tabl);
}
