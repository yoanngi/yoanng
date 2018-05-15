
#include "minishell.h"

t_struct		*ft_my_struct_null(void)
{
    t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	data->path = NULL;
	data->tab_path = NULL;
	data->pwd = NULL;
	data->home = NULL;
	data->current_path = NULL;
	data->env = NULL;
	data->prompt = ft_strdup("$> ");
	data->prompt_current = NULL;
	data->charfound = NULL;
	data->char_echo = NULL;
	data->option_echo = 0;
	data->builtins = ft_initialise_builtins();
	return (data);
}
