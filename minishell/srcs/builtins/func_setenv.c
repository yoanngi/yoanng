/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_setenv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/16 12:57:38 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_valid_env(char *line)
{
	char	*str;
	int		i;
	int		q;

	str = ft_strsub(line, 7, ft_strlen(line) - 7);
	i = 0;
	q = 0;
	while (q == 0)
	{
		if (str[i] == '=')
			q = 1;
		else if (str[i] == '\0')
		{
			ft_strdel(&str);
			ft_putstr_fd("setenv : Invalid format\n", 2);
			return (NULL);
		}
		else
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

static char		**ft_existe_or_not(t_struct *data, char **str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(*str);
	i = 0;
	j = 0;
	while (tmp[i] != '=')
		i++;
	while (data->env[j])
	{
		if (ft_strncmp(data->env[j], tmp, i) == 0)
		{
			ft_strdel(&data->env[j]);
			data->env[j] = ft_strdup(tmp);
			ft_strdel(&tmp);
			ft_strdel(str);
			return (data->env);
		}
		j++;
	}
	ft_strdel(&tmp);
	return (data->env);
}

char			**func_setenv(char **line, t_struct *data)
{
	int		i;
	char	**tmp;
	char	*str;

	i = 0;
	str = NULL;
	str = ft_valid_env(*line);
	data->env = ft_existe_or_not(data, &str);
	if (str == NULL || data->env == NULL)
		return (data->env);
	while (data->env[i])
		i++;
	if (!(tmp = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (data->env[i])
	{
		tmp[i] = ft_strdup(data->env[i]);
		i++;
	}
	tmp[i] = ft_strdup(str);
	tmp[i + 1] = NULL;
	ft_del_tab(data->env);
	ft_strdel(&str);
	return (tmp);
}
