/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delete_struct.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 13:57:17 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 13:45:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Delete struct ans datas
*/

int			ft_delete_struct(t_struct *data)
{
	int		ret;

	ret = data->code_erreur;
	printf("free 1\n");
	data->tab_hash = delete_tab_hash(data->tab_hash, data->sizemax);
	printf("free 2\n");
	data->tab_path = ft_del_tab(data->tab_path);
	printf("free 3\n");
	data->env = ft_del_tab(data->env);
	printf("free 4\n");
	data->builtins = ft_del_tab(data->builtins);
	printf("free 5\n");
	data->env_tmp = ft_del_tab(data->env_tmp);
	printf("free 6\n");
	ft_strdel(&data->pwd);
	printf("free 7\n");
	ft_strdel(&data->oldpwd);
	printf("free 8\n");
	ft_strdel(&data->home);
	printf("free 9\n");
	ft_strdel(&data->charfound);
	printf("free 10\n");
	ft_strdel(&data->current_path);
	printf("free 11\n");
	ft_strdel(&data->prompt);
	printf("free 12\n");
	ft_strdel(&data->prompt_current);
	printf("free 13\n");
	ft_strdel(&data->char_echo);
	printf("free 14\n");
	free(data);
	data = NULL;
	printf("DATA CLEARED\n");
	return (ret);
}
