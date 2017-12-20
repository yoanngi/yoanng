/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 13:37:05 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 15:11:20 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			*ft_modif_str(s_struct *data, int i)
{
	char	*cpy;
	char	*tmp;
	int		ind;

	cpy = ft_strdup(data->s);
	tmp = ft_strdup(data->s);
	ind = 0;
	while (cpy[ind])
	{
		if (cpy[ind] == '%' && i != 0)
			i--;
		if (cpy[ind] == '%' && i == 0)
		{
			tmp = ft_strsub(cpy, 0, ind);
			data->s = ft_strdup(tmp);
			tmp = ft_strsub(cpy, ind, ft_strlen(cpy) - ind);
			ft_strjoin(data->s, tmp);
		}
		ind++;
	}
	ft_strdel(&tmp);
	ft_strdel(&cpy);
	return (0);
}

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
		pvalid++;
	}
	return (0);
}

static int			ft_count_datas(const char **str, s_struct *data, int c)
{
	int		i;
	int		c2;
	int		ret;
	char	*cpy;

	i = 0;
	c2 = 0;
	cpy = ft_strdup(*str);
	data->no_valid = ft_size_tab(data->argc);
	while (cpy[i] != '\0')
	{
		if (cpy[i] == '%')
		{
			if ((ret =ft_argv_valid(cpy, i)) == 1)
			{
				data->no_valid[c][2] = 0;
				c++;
				c2++;
			}
			else
			{
				data->no_valid[c2][2] = 1;
				c2++;
			}
		}
		i++;
	}
	ft_strdel(&cpy);
	return (c);
}

static s_struct		*ft_insert_params(const char **str, int i)
{
	s_struct	*new;

	new = (s_struct *)malloc(sizeof(s_struct));
	new->s = ft_strdup(*str);
	new->flag = 0;
	new->argc = ft_count_datas(str, new, 0);
	new->argv = NULL;
	new->params = NULL;
	if (new->argc > 0)
		new->argv = ft_tab_argv(new, 0, 0);
	while (i != new->argc)
	{
		if (new->no_valid[i][1] == 1 && new->argc == 0)
			ft_modif_str(new, i);
	}
	return (new);
}

int					ft_printf(const char *format, ...)
{
	s_struct	*data;
	va_list		ap;
	int			i;
	void		**tmp;

	data = ft_insert_params(&format, 0);
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
