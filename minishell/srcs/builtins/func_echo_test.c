#include "minishell.h"

static char      *ft_check_option(char *line, int n_or_e)
{
    char    **tab;
    int     ret;

    ret = 0;
    tab = ft_strsplit(line, ' ');
    if (ft_len_tab(tab) >= 2)
    {
        if (ft_strcmp(tab[1], "-n") == 0 && n_or_e == 0)
            ret = 1;
        else if(ft_strcmp(tab[1], "-ne") == 0 && n_or_e == 0)
            ret = 1;
        else if (ft_strcmp(tab[1], "-en") == 0 && n_or_e == 0)
            ret = 1;
        else if (ft_strcmp(tab[1], "-e") == 0 && n_or_e == 1)
            ret = 1;
    }
    ft_del_tab(tab);
    return (ret);
}

static void		option_echo(int j)
{
	if (j == 0)
		ft_putchar('\n');
	else
		ft_putendl("\033[7m%\033[0m");
}

static void     ft_print_special(char *str, int i, int len)
{
    if (i >= len)
        return ;
	if (str[i] == '\\' && (str[i + 1] == 'n' || str[i + 1] == 't' ||
	str[i + 1] == 'a' || str[i + 1] == 'v' || str[i + 1] == 'f'))
	{
		if (str[i + 1] == 'n')
			ft_putstr("\n");
		else if (str[i + 1] == 't')
			ft_putstr("\t");
		else if (str[i + 1] == 'a')
			ft_putstr("\a");
		else if (str[i + 1] == 'v')
			ft_putstr("\v");
		else if (str[i + 1] == 'f')
			ft_putstr("\f");
		return (2);
	}
}

static int     ft_print_echo_suite(char *str, int i, int len, int quote)
{
    if ((str[i] == '\'' || str[i] == '\"') && quote == 1)
        ft_putchar(str[i]);
    else if ((str[i] <= 31) && quote == 1)
    {
        ft_print_special(str, i, len);
        return (2)
    }        
    else if (str[i] > 31)
        ft_putstr(str[i]);
    return (1);
}

static int      ft_search_env(char *str, int i)
{
    char    *search;
    int     len;
    int     i2;

    len = 0;
    i2 = i;
    while(str[i] || str[i] != '\t' || str[i] != ' ' || str[i] != '\n' ||
    str[i] != '\r' || str[i] == '\f' || str[i] == '\v')
        len++;
    search = ft_strsub(str, i2, len);
    i2 = 0;
    while (data->env[i2])
    {
        if (ft_strncmp(data->env[i2], search, ft_strlen(search)) == 0)
        {
            ft_putstr(data->env[i2]);
            i2 = ft_strlen(search);
            ft_strdel(&search);
            return (i2);

        }
    }
    ft_strdel(&search);
    return (0);
}
static void     ft_print_echo(char *str)
{
    int     quote;
    int     i;
    size_t  len;

    quote = 0;
    i = 0;
    len = ft_strlen(str);
    while (str[i])
    {
        if ((str[i] == '\"' || str[i] == '\'') && quote == 0)
        {
            quote = 1;
            i++;
        }
        else if ((str[i] == '\"' || str[i] == '\'') && quote == 1)
            quote = 0;
        if (str[i] == '$')
            i += ft_search_env(str, i);
        else
            i += ft_print_echo_suite(str, i, (int)leni, quote);
    }
}

int				func_echo(char **line, t_struct *data)
{
    char    *str;
    int     i;
    int     tiret_n;
    int     tiret_e;

    tiret_n = ft_check_option(*line, 0);
    tiret_e = ft_check_option(*line, 1);
    i = 0;
    if (tiret_n == 0 && tiret_e == 0)
        str = ft_strsub(*line, 5, ft_strlen(*line) - 5);
    if (tiret_n == 1 || tiret_e == 1)
    {
        while (str[i] == '-' && (str[i + 1] == 'e' || str[i + 1] == 'n')
            i++;
        if (str[i + 2] == ' ' || str[i + 2] == '\0')
            str = ft_strsub(*line, i + 1, ft_strlen(*line) - (i + 1));
        else
            str = ft_strsub(*line, i + 2, ft_strlen(*line) - (i + 2));
    }
    ft_print_echo(str);
    option_echo(tiret_n);
    ft_strdel(&str);
}