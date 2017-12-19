/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printfargv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 10:58:23 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 10:57:35 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static	char	*ft_add_int(s_struct *data, char *cpy, int i, int flag)
{
	
}*/

static	char	*ft_add_string(s_struct *data, int i, int flag)
{
	int index;
	char *tmp;
	// FLAG a GERER
	flag = 0;

	index = 0;
	tmp = ft_strnew(ft_strlen(data->s) + ft_strlen(data->params[i]));
	while (data->s[index] != '%')
		index++;
	tmp = ft_insert_word(tmp, data, index, data->params[i]);
	ft_delete_one_colun(data->argv, data->argc);
	data->s = tmp;
	ft_strdel(&tmp);
	return (data->s);

}

static	int		ft_analyse_data(char *cpy, int compt, int flag)
{
	if (flag == 0 && (cpy[compt] == '%' || cpy[compt] == '+'))
		return (3);
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
**	data->params	= Tab(valeur de format)
*/
int				ft_printfargv(s_struct *data, int i)
{
	int		compt;
	int		retour;
	int		flag;
	char	*cpy;

	flag = 0;
	while (i != data->argc)
	{
		compt = 0;
		cpy = ft_strdup(data->argv[compt]);
		retour = ft_analyse_data(cpy, compt + 1, flag);
		if (retour == 1)
		{
			ft_putstr("Un int !");
			//data->s = ft_add_int(data, cpy, i, flag);
		}
		else if (retour == 2)
			data->s = ft_add_string(data, i, flag);
		else if (retour == 3)
		{
			flag = 1;
			retour = ft_analyse_data(cpy, compt + 1, flag);
		}
		else
			ft_putstr("ERROR\n");
		ft_strdel(&cpy);
		i++;
	}
	ft_putstr(data->s);
	//ft_print_line_final(data);
	return (0);
}
