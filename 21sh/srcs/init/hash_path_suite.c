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
**  Retourne la sommes total
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

int         ft_insert_collision(t_infos **start, t_infos *next)
{
    while (*start)
        *start = (*start)->next;
    (*start)->next = next;
    return (0);
}

int         ft_insert_hash(char *str, int hash, long **tabh, char *tabp)
{
    t_infos     *infos;

    infos = NULL;
    if (tabh[hash][0] == 0)
    {
        tabh[hash][0] = hash;
        infos = init_infos(tabp, str);
        tabh[hash][1] = &infos;
    }
    else
    {
        infos = init_infos(tabp, str);
        ft_insert_collision(tabh[hash][1], infos);
    }
    return (0);
}

int         ft_readforhash(int sizemax, char **tabp, long **tabh, long(*f)(char *, int))
{
    int             i;
    DIR             *dir;
    struct dirent   *fl;
    long             hash;

    i = 0;
    while (tabp[i])
    {
        if (!(dir = opendir(tabp[i])))
            return (EXIT_FAILURE);
        while ((fl = readdir(dir)))
        {
            hash = 0;
            if (ft_strcmp(fl->d_name, ".") != 0 || ft_strcmp(fl->d_name, "..") != 0)
            {
                hash = (*f)(fl->d_name, sizemax);
                ft_insert_hash(fl->d_name, hash, tabh, tabp[i]);
            }
        }
        closedir(dir);
        i++;
    }
    return (EXIT_SUCCESS);
}
