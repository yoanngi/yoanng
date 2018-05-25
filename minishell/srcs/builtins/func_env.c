/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   func_env.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/15 13:22:16 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/17 15:25:43 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_is_commande(t_struct *data, char *str)
{
	int		i;

	i = 0;
	while (data->tab_path[i])
	{
		if (good_path(data->tab_path[i], str, 0) == 1)
			return (i);
		i++;
	}
	return (0);
}

static void		ft_env(t_struct *data, char **tmp, int i, int option)
{
	int		x;
	char	*tmp2;
	char	*ttt;

	x = 0;
	while (tmp[i])
	{
		if (tmp[i][0] == '-' && ft_strlen(tmp[i]) > 1)
			ft_print_usage(tmp[i]);
		else if ((x = ft_is_commande(data, tmp[i])) != 0)
		{
			tmp2 = ft_strjoin(data->tab_path[x], "/");
			ttt = ft_strjoin(tmp2, tmp[0]);
			if (option == 1)
				ft_process(ttt, tmp, data->env);
			else
				ft_process(ttt, tmp, NULL);
			ft_strdel(&tmp2);
			ft_strdel(&ttt);
			return ;
		}
		else
			ft_error_dir("env : ", tmp[0]);
		i++;
	}
}

/*
**	Core env
*/

void			func_env(char **line, t_struct *data)
{
	char	**tmp;
	int		i;
	size_t	len;

	tmp = NULL;
	i = 0;
	ft_check_line(data, line, 0);
	tmp = ft_strsplit(*line, ' ');
	len = ft_len_tab(tmp);
	while (tmp[i] && ft_strcmp(tmp[i], "env") == 0)
		i++;
	if ((int)len == i)
		print_full_env(data);
	else
	{
		ft_del_tab(tmp);
		tmp = ft_strsplit(*line + (i * 4), ' ');
		if (ft_options_i(tmp, i) == 0)
			ft_env(data, tmp, 0, 0);
		else
			ft_env(data, tmp, 0, 1);
	}
	ft_del_tab(tmp);
}
