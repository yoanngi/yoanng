# include "ft_ls.h"

static void			swap_light(t_rep **s1, t_rep **s2)
{
	time_t	tmp;
	char	*tmp2;

	tmp = (*s1)->date;
	tmp2 = (*s1)->name;
	(*s1)->date = (*s2)->date;
	(*s1)->name = (*s2)->name;
	(*s2)->date = tmp;
	(*s2)->name = tmp2;
}

static t_rep		*reverse_dir(t_rep *prime)
{
	t_rep	*tete;
	t_rep	*sui;

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
	t_rep	*cpy;

	cpy = *lst;
	if (data->tmin == 1)
		*lst = class_time(cpy);
	if (data->rmin == 1)
		*lst = reverse_dir(cpy);
}
