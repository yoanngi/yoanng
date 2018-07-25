/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 13:36:26 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 16:59:45 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
**	Execute une commande avec env modifier
*/

static int		malloc_for_env_suite(char ***str, t_struct *data, t_cmd *lst, int i)
{
	int		j;

	j = 0;
	while (data->env[j])
	{
		if (!((*str)[j] = ft_strdup(data->env[j])))
			return (1);
		j++;
	}
	while (lst->tab_cmd[i] || ft_strstr(lst->tab_cmd[i], "=") != NULL)
	{
		printf("---->%s\n", lst->tab_cmd[i]);
		if (!((*str)[j] = ft_strdup(lst->tab_cmd[i])))
			return (1);
		i++;
		j++;
	}
	return (0);	
}

static char		**malloc_for_env(t_struct **data, t_cmd **lst, int i, int opt)
{
	char		**new;
	int			len;
	int			x;

	new = NULL;
	len = 0;
	x = 0;
	if (opt == 1)
	{
		len = i + 1;
		if (!(new = (char **)malloc(sizeof(char *) * len)))
			return (NULL);
		while ((*lst)->tab_cmd[i] && ft_strstr((*lst)->tab_cmd[i], "=") != NULL)
		{
			new[x] = ft_strdup((*lst)->tab_cmd[i]);
			i++;
			x++;
		}
	}
	else
	{
		while ((*data)->env[len])
			len++;
		len += (i + 1);
		if (!(new = (char **)malloc(sizeof(char *) * len)))
			return (NULL);
		if (malloc_for_env_suite(&new, *data, *lst, i) == 1)
		{
			new = ft_del_tab(new);
			return (NULL);
		}
	}
	return (new);
}

int				execute_var_modif(t_struct *data, t_cmd **lst, int i, int opt)
{
	int		j;
	int		ret;
	char	**new;

	j = i;
	ret = 0;
	new = NULL;
	while ((*lst)->tab_cmd[j] || ft_strstr((*lst)->tab_cmd[j], "=") != NULL)
		j++;
	new = malloc_for_env(&data, lst, j, opt);
	if (new == NULL)
		return (1);
	(*lst)->env = ft_del_tab((*lst)->env);
	(*lst)->env = ft_duplicate_tab(new);
	printf("***********************************\n");
	// sa ne marche pas
	i = 0;
	while (new[i])
	{
		ft_putendl(new[i]);
		i++;
	}
	printf("***********************************\n");
	new = ft_del_tab(new);
	j = i;
	ret = execute_with_env(&data, *lst, j, 0);
	return (ret);
}
