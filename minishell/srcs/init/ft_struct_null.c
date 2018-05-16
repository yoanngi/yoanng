/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_struct_null.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 13:57:32 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 13:58:05 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_return_pwd(void)
{
	char	*buf;

	buf = ft_strnew(512);
	buf = getcwd(buf, 512);
	return (buf);
}

t_struct		*ft_my_struct_null(void)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	data->path = NULL;
	data->tab_path = NULL;
	data->pwd = ft_return_pwd();
	data->oldpwd = NULL;
	data->home = NULL;
	data->current_path = NULL;
	data->env = (char **)malloc(sizeof(char *) * 2);
	data->env[0] = ft_strjoin("PWD=", data->pwd);
	data->env[1] = NULL;
	data->prompt = ft_strdup("$> ");
	data->prompt_current = NULL;
	data->charfound = NULL;
	data->char_echo = NULL;
	data->option_echo = 0;
	data->builtins = ft_initialise_builtins();
	return (data);
}
