/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 10:11:53 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/18 12:07:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			init_info(t_info *info)
{
	raw_term_mode(info);
	info->s_len = 0;
	info->orig_y = CURS_Y;
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
	info->line = NULL;
	info->curs_in_str = 1;
	ioctl(0, TIOCGWINSZ, &(info->wndw));
	info->row_nb = info->wndw.ws_row;
	info->col_nb = info->wndw.ws_col;
	info = memo_info(info, 0);
	info->prmpt = NULL;
	info->prmpt = ft_strdup("$> ");
	info->history = root_hist();
}

void			reinit_info(t_info *info)
{
	raw_term_mode(info);
	info->s_len = 0;
	info->orig_y = CURS_Y;
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
	info->curs_in_str = 1;
	ft_strdel(&(info->line));
}

static t_info	line_edit(t_info info, t_hist *tmp)
{
	int loop;

	raw_term_mode(&info);
	add_head(info.history);
	tmp = last_elem(info.history);
	init_current(info.history);
	loop = 1;
	ft_putstr(MAGENTA);
	ft_putstr(info.prmpt);
	ft_putstr(RESET);
	while (loop)
	{
		get_signals();
		get_key(&loop, &info, tmp);
	}
	return (info);
}

/*
**	parse_line : Parse la line et la convertit en liste chainer
**	Execute la / les commandes
*/

static int		parse_line(t_struct *data, char **line)
{
	int ret;
	t_ins *cpy;

	ret = 0;
	data->commandes = ft_split_commandes(line, data);
	cpy = data->commandes;
	while (cpy)
	{
		if (cpy->cmd != NULL)
			ret = execute_commandes(data, cpy->cmd);
		if (ret == -1)
		{
			ft_putstr_fd("--> exit 21sh <--\n", 2);
			data->commandes = clear_ins(data->commandes);
			return (1);
		}
		data->code_erreur = ret;
		// A DETETE **********************************************************
		ft_printf("******* Valeur de retour (data->code_erreur) = %d\n", data->code_erreur);
		// *******************************************************************
		cpy = cpy->next;
	}
	data->commandes = clear_ins(data->commandes);
	return (0);
}

/*
**	Boucle infini, Attend un retour different de zero pour exit
*/

void			core_shell(t_struct *data)
{
	int		quit;
	t_info	info;
	t_hist	*tmp;

	quit = 0;
	tmp = NULL;
	init_info(&info);
	while (quit == 0)
	{
		info = line_edit(info, tmp);
		if (info.line != NULL && quit == 0)
		{
			default_term_mode(&info);
			printf("********************************************* LINE = |%s|***\n\n", info.line);
			quit = parse_line(data, &(info.line));
			ft_strdel(&(info.line));
		}
		reinit_info(&info);
	}
	default_term_mode(&info);
}
