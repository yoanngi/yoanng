/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_insert_dollar.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/22 11:56:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 11:58:36 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**  replace $ for the path and return len var env
*/

char			*ft_insert_dollar(t_struct *data, char **str, int i, int len)
{
	char	*new;
	char	*tmp;
	
	new = NULL;
	tmp = NULL;
	new = ft_strsub(*str, i, len);
	tmp = ft_check_infos(data->env, new + 1);
	ft_strdel(&new);
	if (tmp == NULL)
		return (NULL);
	new = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
	ft_strdel(&tmp);
	return (new);
}

char			*ft_insert_moins(t_struct *data, char **str, int i, int len)
{
	char	*new;
	char	*tmp;
	int		j;
	
	j = 0;
	new = NULL;
	tmp = NULL;
	(void)str;
	if (len != 1)
		return (NULL);
	if (i < 3)
		return (NULL);
	if (ft_strstr(*str, "cd -") == NULL)
		return (NULL);
	tmp = ft_check_infos(data->env, "OLDPWD=");
	if (tmp == NULL)
		return (NULL);
	new = ft_strsub(tmp, 7, ft_strlen(tmp) - 7);
	ft_strdel(&tmp);
	return (new);
}

char			*ft_insert_home(t_struct *data, char **str, int i, int len)
{
	char	*new;
	char	*tmp;
	
	new = NULL;
	tmp = NULL;
	(void)str;
	(void)i;
	(void)len;
	tmp = ft_check_infos(data->env, "HOME=");
	if (tmp == NULL)
		return (NULL);
	new = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
	ft_strdel(&tmp);
	return (new);
}
