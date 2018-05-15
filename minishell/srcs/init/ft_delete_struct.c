
#include "minishell.h"

/*
**	Delete struct ans datas
*/

void			ft_delete_struct(t_struct *data)
{
	ft_strdel(&data->path);
	ft_strdel(&data->pwd);
	ft_strdel(&data->home);
	ft_strdel(&data->charfound);
	ft_strdel(&data->current_path);
	ft_strdel(&data->prompt);
	ft_strdel(&data->prompt_current);
	ft_del_tab(data->tab_path);
	ft_del_tab(data->env);
	ft_del_tab(data->builtins);
	free(data);
	data = NULL;
}
