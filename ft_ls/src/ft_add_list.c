#include "ft_ls.h"

t_lst		*ft_add_list(void)
{
	t_lst	*data;

	data = (t_lst *)malloc(sizeof(t_lst));
	if (data == NULL)
		return (NULL);
	data->name = NULL;
	data->params = NULL;
	data->size = 0;
	data->previous = NULL;
	data->next = NULL;
	return &(*data);
}

t_lst	ft_list_add_ls(t_lst *data, t_dir *fichierlu)
{
	DIR		*dir;

	if ((dir = opendir(fichierlu->d_name)) == NULL)
		exit(1);
	data->name = ft_strdup((const char *)fichierlu);
	while ((fichierlu = readdir(dir)) != NULL)
	{
		data->size += 1;
		ft_putstr(fichierlu->d_name);
		ft_putstr("\n");
	}
	return (*data);
}
