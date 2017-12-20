/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 13:37:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 11:30:17 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_argv_valid(char *str, int index)
{
	int		pvalid;
	char	*c;

	pvalid = 0;
	c = "sSpdDioOuUxXcChljz#0-+";
	while (pvalid != 22)
	{
		if (str[index] == '%' && str[index + 1] == c[pvalid])
			return (1);
		else if (str[index] == '%' && str[index + 1] == '%')
			return (index);
		pvalid++;
	}
	return (0);
}

static int			ft_count_datas(const char **str, s_struct *data)
{
	int		i;
	int		ret;
	int		count;
	char	*cpy;

	i = 0;
	count = 0;
	cpy = ft_strdup(*str);
	while (cpy[i] != '\0')
	{
		if (cpy[i] == '%')
		{
			if ((ret =ft_argv_valid(cpy, i)) == 1)
				count++;
			else if ((ret == ft_argv_valid(cpy, i)) != 1)
				data->flag = ret;
		}
		i++;
	}
	if (data->flag == 1 && count == 0)
		data->s = ft_insert_word(data->s, data, ret, "% ");
	ft_strdel(&cpy);
	return (count);
}

static s_struct		*ft_insert_params(const char **str)
{
	s_struct	*new;

	new = (s_struct *)malloc(sizeof(s_struct));
	new->s = ft_strdup(*str);
	new->flag = 0;
	new->argc = ft_count_datas(str, new);
	new->argv = NULL;
	new->params = NULL;
	if (new->argc > 0)
		new->argv = ft_tab_argv(new, 0, 1);
	return (new);
}

int					ft_printf(const char *format, ...)
{
	s_struct	*data;
	va_list		ap;
	int			i;
	void		**tmp;

	data = ft_insert_params(&format);
	i = 0;
	if (data->argc == 0)
	{
		ft_putstr("DEBUG_PAS D'ARGUMENTS\n");
		ft_putstr(data->s);
	}
	else
	{
		va_start(ap, format);
		if (!(tmp = (void **)malloc(sizeof(void *) * (data->argc + 1))))
			return (0);
		while (i < data->argc + 1)
		{
			tmp[i] = va_arg(ap, void *);
			i++;
		}
		va_end(ap);
		data->params = tmp;
		ft_printfargv(data, 0);
	}
	return (ft_strlen(data->s));
}
