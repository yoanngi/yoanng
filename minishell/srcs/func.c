#include "minishell.h"

/*
**  Delete tab and return NULL
*/
char        *ft_del_tab(char **tab)
{
    int i;

    i = 0;
    if (!*tab)
        return (NULL);
    while(tab[i])
    {
        ft_strdel(&tab[i]);
        i++;
    }
    free(tab);
    tab = NULL;
    return (NULL);
}