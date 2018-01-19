/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printfargv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 10:58:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 10:53:47 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_add_int(s_struct *data, int i, int flag)
{
	int		index;
	int		x;
	char	*tmp;

	flag = 0;
	index = 0;
	x = 0;
	data->params[i] = ft_itoa((char)data->params[i]);
	while (data->s[index] != '%' && x != 1)
	{
		if (ft_argv_valid(data->s, index) == 1)
			x = 1;
		index++;
	}
	tmp = ft_insert_word(data, index, i);
	data->s = ft_strdup(tmp);
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
	else if (cpy[compt] == 's')
		return (2);
	else if (cpy[compt] == 'd' || cpy[compt] == 'i')
		return (1);
	//else
	//	ft_analyse_data(cpy, compt + 1, flag);
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
		retour = ft_analyse_data(cpy, compt + 1, flag);
		if (retour == 1)
			data->s = ft_add_int(data, i, flag);
		else if (retour == 2)
			data->s = ft_add_string(data, i, flag);
		else if (retour == 3)
		{
			flag = ft_analyse_flag(data, 0);
			//data->s = ft_add_complexe(data, i);
		}
		ft_strdel(&cpy);
		i++;
	}
	ft_print_line_final(data);
	return (ft_strlen(data->s));
}
