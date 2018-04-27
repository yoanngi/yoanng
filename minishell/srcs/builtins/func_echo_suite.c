/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_echo_suite.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 15:49:40 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print good line env
*/

void			echo_env(char *str, t_struct *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
	while (data->env[i])
	{
		if (ft_strncmp(tmp, data->env[i], ft_strlen(tmp)) == 0)
			ft_putstr(data->env[i] + ft_strlen(str));
		i++;
	}
	ft_strdel(&tmp);
}

/*
 **	Check special char && print line
 */

static int		echo_b(char **cpy, int i, int len)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(*cpy, 0, i - 1);
	tmp2 = ft_strsub(*cpy, i + 2, len - i - 2);
	ft_strdel(cpy);
	*cpy = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (0);
}

static int		echo_r(char **cpy, int i, int len)
{
	char	*tmp;

	tmp = ft_strsub(*cpy, i + 2, len - i - 2);
	ft_strdel(cpy);
	*cpy = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (0);
}

void			echo_clear_special(char **str)
{
	int		i;
	size_t	len;
	char	*cpy;

	i = 0;
	len = ft_strlen(*str);
	cpy = ft_strdup(*str);
	if (ft_strstr(cpy, "\\r") != NULL || ft_strstr(cpy, "\\b") != NULL)
	{
		while (i < (int)len)
		{
			if (cpy[i] == '\\' && cpy[i + 1] == 'r')
				i = echo_r(&cpy, i, len);
			if (cpy[i] == '\\' && cpy[i + 1] == 'b')
				i = echo_b(&cpy, i, len);
			len = ft_strlen(cpy);
			i++;
		}
		ft_strdel(str);
		*str = ft_strdup(cpy);
		ft_strdel(&cpy);
	}
	ft_strdel(&cpy);
}

/*
 **	Print line and check \[...]
 */

void			echo_clear_string_simple(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		if (str[i] == '\0')
			return ;
		else if (str[i] == '\\' && str[i + 1] != '\\')
		{
			i++;
			ft_putchar(str[i]);
		}
		else if (str[i] == '\\' && str[i + 1] == '\\')
		{
			ft_putstr("\t");
			i += 2;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
