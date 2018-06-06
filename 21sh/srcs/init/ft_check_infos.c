/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_infos.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 12:57:34 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 13:34:56 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**	Take infos in Env
*/

char		*ft_check_infos(char **env, char *find)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strstr(env[i], find))
		{
			path = ft_strdup(env[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}
