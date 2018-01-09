/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printfargv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 10:58:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 14:47:06 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_int(s_struct *data, int i, int flag)
{
	int		index;
	char	*tmp;
	char	*in_t;

	flag = 0;
	index = 0;
	in_t = ft_itoa((char)data->params[i]);
	tmp = ft_strnew(ft_strlen(data->s) + ft_strlen(in_t));
	while (data->s[index] != '%')
		index++;
	tmp = ft_insert_word(tmp, data, index, in_t);
	data->s = ft_strdup(tmp);
	ft_strdel(&in_t);
	ft_strdel(&tmp);
	return (data->s);
}

static char		*ft_add_string(s_struct *data, int i, int flag)
{
	int		index;
	int		pos;
	char	*tmp;

	flag = 0;
	index = 0;
	pos = 0;
	// tmp = ft_strnew(ft_strlen(data->s) + ft_strlen(data->params[i]));
	while (data->s[index] != '%')
		index++;
	tmp = ft_insert_word(data, index, i);
	data->s = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (data->s);
}

static int		ft_analyse_data(char *cpy, int compt, int flag)
{
	if (ft_strlen(cpy) == (size_t)compt)
		return (0);
	if (flag == 0 && (cpy[compt] == '+' || cpy[compt] == '#' ||
	cpy[compt] == '0' || cpy[compt] == '-' || cpy[compt] == ' '))
		return (3);
	else if (flag == 0 && cpy[compt] == '%')
		return (4);
	else if (cpy[compt] == 's')
		return (2);
	else if (cpy[compt] == 'd' || cpy[compt] == 'i')
		return (1);
	else
		ft_analyse_data(cpy, compt + 1, flag);
	return (0);
}

/*
**	ft_printargv :
**	data->argc		= Nombre de parametre
**	data->s			= String format
**	data->argv		= Tab (format)
**	data->no_valid	= Argument valide ou pas
**	data->params	= Tab(valeur de format)
*/

int				ft_printfargv(s_struct *data, int i)
{
	int		compt;
	int		retour;
	int		flag;
	char	*cpy;

	flag = 0;
	compt = 0;
	while (i != data->argc)
	{
		cpy = ft_strdup(data->argv[i]);
		printf("Debug, Valeur de cpy = %s\n", cpy);
		printf("Debug, Valeur de s = %s\n", data->s);
		retour = ft_analyse_data(cpy, compt + 1, flag);
		if (retour == 1)
		{
			printf("int\n");
			data->s = ft_add_int(data, i, flag);
		}
		else if (retour == 2)
		{
			printf("string\n");
			data->s = ft_add_string(data, i, flag);
		}
		else if (retour == 3)
		{
			flag = 1;
			retour = ft_analyse_data(cpy, compt + 2, flag);
		}
		else if (retour == 4)
		{
			printf("double modulo\n");
		}
		ft_strdel(&cpy);
		i++;
	}
	ft_print_line_final(data);
	return (ft_strlen(data->s));
}
