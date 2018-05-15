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

char	**func_setenv(char **line, t_struct *data)
{
	int		i;
	char	**tmp;

	i = 0;
	if (data->env == NULL)
		return (NULL);
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
	tmp[i] = ft_strsub(*line, 7, ft_strlen(*line) - 7);
	tmp[i + 1] = NULL;
	ft_del_tab(data->env);
	return (tmp);
}
