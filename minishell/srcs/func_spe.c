#include "minishell.h"

/*
**  func_bracket : check ( && {
*/

static int      func_bracket(char **line, char **line_2, t_struct *data)
{
    (void)line;
    (void)line_2;
    (void)data;
    return (0);
}

/*
**  func_spe : check ' && "
**  39 = '
**  34 = "
*/

int             func_spe(char **line, char **line_2, t_struct *data)
{
    char    *str;
    char    *tmp;

    str = NULL;
    tmp = NULL;
    if (*line[0] == 34 || *line[0] == 39)
    {
        str = ft_strdup("\\n");
        tmp = ft_strdup(*line);
        ft_strdel(line);
        *line = ft_strjoin(tmp, str);
        ft_strdel(&tmp);
        tmp = ft_strjoin(*line, *line_2);
        ft_strdel(line);
        ft_strdel(&str);
        *line = ft_strdup(tmp);
        ft_strdel(&tmp);
    }
    else
        func_bracket(line, line_2, data);
    return (0);
}