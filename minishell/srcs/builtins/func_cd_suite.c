/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_cd_suite.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 09:12:25 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/16 09:12:28 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

/*
**	For builtins/func_cd.c
**	Check data in t_struct *data
*/

void		ft_check_error_cd(t_struct **data)
{
	char	*buf;

	buf = NULL;
	if ((*data)->home == NULL)
		(*data)->home = ft_strdup("/");
	if ((*data)->pwd == NULL)
	{
		buf = ft_strnew(512);
		buf = getcwd(buf, 512);
		(*data)->pwd = ft_strdup(buf);
		ft_strdel(&buf);
	}
	if ((*data)->oldpwd == NULL)
		(*data)->oldpwd = ft_strdup((*data)->pwd);
}
