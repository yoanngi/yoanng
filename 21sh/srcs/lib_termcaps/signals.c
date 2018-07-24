/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   signals.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 12:14:19 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/24 15:11:04 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		resize(t_info *info)
{
	t_hist	*tmp;
	int		i;

	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
	tmp = last_elem(info->history);
	ioctl(0, TIOCGWINSZ, &(info->wndw));
	info->row_nb = info->wndw.ws_row;
	info->col_nb = info->wndw.ws_col;
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar_err);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	print_prompt(info);
	ft_putstr(info->line);
	info->orig_y = 1;
	i = info->s_len + 1;
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
	while (i > info->curs_in_str)
	{
		left_key(info);
		info->curs_in_str++;
		i--;
	}
	tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
}

static void		resize_win(int sig)
{
	(void)sig;
	resize(&g_info);
}

static void		stop_shell(t_info *info)
{
	char	s[2];

	s[0] = info->term.c_cc[VSUSP];
	s[1] = 0;
	default_term_mode(info);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, s);
}

static void		stop(int sig)
{
	(void)sig;
	stop_shell(&g_info);
}

static void		restart_shell(t_info *info)
{
	signal(SIGTSTP, stop);
	raw_term_mode(info);
	resize(info);
}

static void		restart(int sig)
{
	(void)sig;
	restart_shell(&g_info);
}


void			get_signals(void)
{
	signal(SIGWINCH, resize_win);
	signal(SIGTSTP, stop);
	signal(SIGCONT, restart);
}
