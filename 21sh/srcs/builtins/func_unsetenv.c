/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_unsetenv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:42 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 12:20:55 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			func_unsetenv(t_struct *data, t_cmd *lst)
{
	/*
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_len_tab(data->env);
	tmp = ft_return_tmp(*line);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], tmp, ft_strlen(tmp)) == 0)
		{
			ft_strdel(&tmp);
			while (i != len - 1)
			{
				ft_delete(data, i);
				i++;
			}
			ft_strdel(&data->env[i]);
			return (data->env);
		}
		i++;
	}
	ft_error_unset(tmp, 1);
	ft_strdel(&tmp);
	return (data->env);
	*/
	(void)data;
	(void)lst;
	return (0);
}
