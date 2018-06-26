/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 15:00:57 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 12:59:41 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/shell.h"

void		init_info(t_info *info)
{
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
	info->prompt = ft_strdup("$> ");
	info->history = ft_lstnew(NULL, 0);
}

static void	line_edit(void)
{
	int		loop;
	t_info	info;
	t_list	*tmp;

	loop = 1;
	raw_term_mode(&info);
	init_info(&info);
	tmp = info.history;
//	ft_printf("nb_cols: %d, nb_rows = %d\n", info.wndw.ws_col, info.wndw.ws_row);
	while (loop)
	{
		get_signals();
		get_key(&loop, &info);
		tmp->content = ft_strdup(info.line);
		tmp->next = ft_lstnew(NULL, 0);
		tmp = tmp->next;
	}
	get_line(1, &(info.line));
	default_term_mode(&info);
}

int			main(int argc, char **argv, char **env)
{
//	t_struct	*data;

	(void)argc;
	(void)argv;
	(void)env;
	while (1)
		line_edit();
	/*
	data = init_struct(env);
	core_shell(&line, data);
	ft_strdel(&line);
	ft_delete_struct(data);*/
	return (0);
}
