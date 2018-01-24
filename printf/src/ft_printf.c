/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 11:30:08 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 10:21:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_count_datas(const char **str, int count)
{
	int		i;
	int		ret;
	char	*cpy;

	i = 0;
	cpy = ft_strdup(*str);
	while (cpy[i] != '\0')
	{
		if (cpy[i] == '%')
		{
			if ((ret = ft_argv_valid(cpy, i)) == 1)
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
	new->argc = ft_count_datas(str, 0);
	if (new->argc > 0)
		new->argv = ft_tab_argv(new, 0, 0);
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
		ft_putstr(data->s);
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
	}
	return (ft_parse(data));
}
