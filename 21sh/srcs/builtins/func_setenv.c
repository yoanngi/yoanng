/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_setenv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:35 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/26 16:36:44 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Check error
*/

static int		ft_check_error_setenv(t_cmd **lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*lst)->tab_cmd[i])
	{
		if (i == 1)
		{
			while ((*lst)->tab_cmd[i][j])
			{
				(*lst)->tab_cmd[i][j] = ft_toupper((*lst)->tab_cmd[i][j]);
				j++;
			}
		}
		i++;
	}
	if (i != 3)
	{
		ft_putstr_fd("setenv: Invalid format\n", (*lst)->stderr_cmd);
		return (1);
	}
	return (0);
}

/*
**	Modifie la new setenv in env
*/

static int		modifie_env(t_struct **data, t_cmd *lst, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(lst->tab_cmd[1], "=");
	tmp2 = ft_strjoin(tmp, lst->tab_cmd[2]);
	ft_strdel(&(*data)->env[i]);
	(*data)->env[i] = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	if (ft_strcmp(lst->tab_cmd[1], "PATH") == 0)
	{
		(*data)->tab_hash = delete_tab_hash((*data)->tab_hash,
	(*data)->sizemax);
		(*data)->sizemax = ft_load_path(data);
		if ((*data)->sizemax == -1)
			return (1);
	}
	return (0);
}

/*
**	Add new setenv in env
*/

static int		add_in_env(t_struct **data, t_cmd *lst)
{
	int		i;
	char	**new;
	char	*tmp;

	i = 0;
	new = NULL;
	tmp = NULL;
	while ((*data)->env[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char *) * i + 2)))
		return (1);
	i = 0;
	while ((*data)->env[i])
	{
		new[i] = ft_strdup((*data)->env[i]);
		i++;
	}
	tmp = ft_strjoin(lst->tab_cmd[1], "=");
	new[i] = ft_strjoin(tmp, lst->tab_cmd[2]);
	ft_strdel(&tmp);
	new[i + 1] = NULL;
	(*data)->env = ft_del_tab((*data)->env);
	if ((*data)->env != NULL)
		printf("NON NULL\n");
	(*data)->env = ft_duplicate_tab(new);
	// free not allocated ??? WHY !!!!!!!!!!
	new = ft_del_tab(new);
	return (0);
}

/*
**	Return la len jusqu'qu egal
*/

static int		return_len(char *str)
{
	int		i;

	i = 0;
	if (ft_strstr(str, "=") == NULL)
		return (0);
	while (str[i])
	{	
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

/*
**	Core setenv
*/

int				func_setenv(t_struct **data, t_cmd *lst)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ft_check_error_setenv(&lst) == 1)
		return (1);
	while ((*data)->env[i])
	{
		len = return_len((*data)->env[i]); 
		if (ft_strncmp((*data)->env[i], lst->tab_cmd[1], len) == 0)
			return (modifie_env(data, lst, i));
		i++;
	}
	if (add_in_env(data, lst) == 1)
	{
		ft_putstr_fd("setenv: Error d'allocation\n", lst->stderr_cmd);
		return (1);
	}
	return (0);
}
