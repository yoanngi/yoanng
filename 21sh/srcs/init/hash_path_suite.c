/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hash_path_suite.c                                .::    .:/ .      .::   */
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
**	On compte le nombre de fichier a mettre dans la table
*/

int         ft_count(char *path)
{
    DIR             *dir;
    struct dirent   *fl;
    int             i;

    i = 0;
    if (!(dir = opendir(path)))
        return (EXIT_FAILURE);
    while ((fl = readdir(dir)))
        i++;
    closedir(dir);
    return (i);
}

/*
**  Applique une fonction sur l'ensemble du tableau envoyer en parametre
**  Retourne la somme total
*/

int         ft_work_in_tab(char **tabl, int(*ft)(char *))
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (tabl[i])
    {
        count += (*ft)(tabl[i]);
        i++;
    }
    return (count);
}

/*
**  Insertion et calcul des hash dans la table
*/

int         ft_insert_hash(int sizemax, char **tabp, long **tabh, long(*f)(char *, int))
{
    int             i;
    DIR             *dir;
    struct dirent   *fl;
    long             hash;
    //t_infos          *infos;

    i = 0;
    hash = 0;
    int col = 0;
    int nocol = 0;
    int j = 0;
    while (tabp[i] != NULL)
    {
        if (!(dir = opendir(tabp[i])))
            return (EXIT_FAILURE);
        while ((fl = readdir(dir)))
        {
            j++;
            if (ft_strcmp(fl->d_name, ".") != 0 || ft_strcmp(fl->d_name, "..") != 0)
            {
                hash = (*f)(fl->d_name, sizemax);
                printf("hash = %ld -> ", hash);
                if (tabh[hash][0] == 0)
                {
                    nocol++;
                    printf("PAS DE Colision (%d / %d) ! -> %s\n", nocol, j, fl->d_name);
    //                tabh[hash][0] = hash;
                    //infos = init_infos(tabp[i], fl->d_name);
                    //tabh[hash][1] = (long)&infos;
                }
                else
                {
                    col++;
                    printf("COLLISION (%d / %d)! -> %s\n", col, j, fl->d_name);
                }
            }
        }
        closedir(dir);
        i++;
    }
    printf("END\n");
    return (EXIT_SUCCESS);
}
