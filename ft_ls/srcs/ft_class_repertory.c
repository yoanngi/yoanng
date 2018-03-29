# include "ft_ls.h"

static void			swap_light(t_rep **s1, t_rep **s2)
{
	int		tmp;
	char	tmp2;

	tmp = (*s1)>date:
	tmp2 = (*s1)>name:
	(*s1)->date = (*s2)->date;
	(*s1)->name = (*s2)->name;
	(*s2)->next->date = tmp;
	(*s2)->next->date = tmp2;
}

static t_rep		*reverse_dir(t_dir *prime)
{
	t_dir	*tete;
	t_dir	*sui;

	tete = NULL;
	sui = NULL;
	while (prime)
	{
		sui = prime->next;
		prime->next = tete;
		tete = prime;
		prime = sui;
	}
	return (tete);
}

static int		class_time_suite(t_rep **lst)
{
	int		i;
	int		tmp;
	char	*tmp2;

	i = 0;
	if ((*lst)->next && (*lst)->date < (*lst)->next->date)
	{
		swap_light(lst, &(*lst)->next);
		i++;
	}
	else if ((*lst)->next && (*lst)->date == (*lst)->next->date)
	{
		if ((*lst)->next && ft_strcmp((*lst)->name, (*lst)->next->name) > 0)
		{
			swap_light(lst, &(*lst)->next);
			i++;
		}
	}
	return (i);
}

static t_rep		*class_time(t_rep *lst)
{
	t_rep	*start;
	int		i;

	i = 0;
	start = lst;
	while (lst)
	{
		i += class_time_suite(&lst);
		lst = lst->next;
	}
	if (i > 0)
		lst = class_time(start);
	lst = start;
	return (lst);
}

void				ft_class_repertory(t_rep **lst, t_struct *data)
{
	if (data->tmin == 1)
		*lst = class_time(*lst);
	if (data->rmin == 1)
		*lst = ft_reverse_lst(*lst);
}
