#include "minishell.h"

static char		*ft_delete_start(char *str, int len)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strsub(str, len, ft_strlen(str) - len);
	ft_strdel(&str);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (str);
}

static char		*ft_check_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strstr(env[i], "PATH"))
			path = ft_strdup(env[i]);
		i++;
	}
	path = ft_delete_start(path, 5);
	return (path);
}

t_struct		*ft_my_struct(char **env)
{
	t_struct	*data;

	if (!(data = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	data->path = ft_check_path(env);
	return (data);
}

void			ft_delete_struct(t_struct *data)
{
	ft_strdel(&data->path);
	free(data);
	data = NULL;
}
