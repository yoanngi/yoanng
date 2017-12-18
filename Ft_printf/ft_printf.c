/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 13:37:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 14:45:03 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			ft_argv_valid(char *str, int index)
{
	int		pvalid;
	char	*c;

	pvalid = 0;
	c = "sSpdDioOuUxXcC";
	while (pvalid != 14)
	{
		if (str[index] == '%' && str[index + 1] == c[pvalid])
			return (1);
		pvalid++;
	}
	return (0);
}

static int			ft_count_datas(const char **str)
{
	int		i;
	int		count;
	char	*cpy;

	i = 0;
	count = 0;
	cpy = ft_strdup(*str);
	while (cpy[i] != '\0')
	{
		if (cpy[i] == '%')
		{
			if (ft_argv_valid(cpy, i) == 1)
				count++;
		}
		i++;
	}
	ft_strdel(&cpy);
	return (count);
}

static s_struct		*ft_insert_params(const char **str)
{
	s_struct	*new;

	new = (s_struct *)malloc(sizeof(s_struct));
	new->s = ft_strdup(*str);
	new->argc = ft_count_datas(str);
	new->argv = NULL;
	new->params = NULL;
	if (new->argc > 0)
		new->argv = ft_tab_argv(new, 0);
	// DEBUG ************************************************************
	ft_print_carre(new->argv, new->argc);
	// DEBUG ************************************************************
	return (new);
}

int					ft_printf(const char *format, ...)
{
	s_struct	*data;
	va_list		ap;
	int			i;
	char		*tmp;

	tmp = ft_strnew(50);
	data = ft_insert_params(&format);
	i = 0;
	if (data->argc == 0)
		ft_putstr(data->s);
	else
	{
		va_start(ap, format);
		while (i != data->argc)
		{
			printf("**********DEBUG************\n");
			printf("Valeur de va_arg = %c\n", *va_arg(ap, char *));
			//tmp = va_arg(ap, void *);
			//printf("Valeur de tmp = %s\n", tmp);
			i++;
		}
		va_end(ap);
		ft_print_carre(data->params, data->argc);
		ft_printfargv(data);
	}
	return (0);
}
