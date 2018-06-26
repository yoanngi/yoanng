/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keys.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 14:39:02 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 11:38:48 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** INSERT CHAR
** im : insertion mode
** ei : exit insertion mode
*/

void	insert_char(char c, t_info *info)
{
	int		i;

	i = info->curs_in_str - 1;
	tputs(tgetstr("sc", NULL), 1, ft_putchar_err);
	tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
	add_c_in_str(info, c);
	ft_putchar(c);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
	while (i++ < info->s_len)
		ft_putchar(info->line[i]);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
	tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
	right_key(info);
	info->s_len++;
}

void	add_char(char c, t_info *info)
{
	char	chr[2];

	chr[0] = c;
	chr[1] = '\0';
	info->line = !info->line ? ft_strdup(chr) : str_append(info->line, chr);
	ft_putchar(c);
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
	info->curs_in_str++;
	info->s_len++;
}

/*
** DELETE CHAR
** dm : delete mode
** ed : exit delete mode
** dc : delete char
*/

void	del_char(t_info *info)
{
	int	i;

	if (info->s_len && (info->curs_x > 1 || info->curs_y - info->orig_y))
	{
		left_key(info);
		i = info->curs_in_str - 2;
		tputs(tgetstr("sc", NULL), 1, ft_putchar_err);
		tputs(tgetstr("cd", NULL), 1, ft_putchar_err);
		del_c(info);
		tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
		while (i++ < info->s_len - 1)
			ft_putchar(info->line[i]);
		tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
		tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
		info->s_len--;
	}
}

void	alt_up_down(t_info *info, char *buff)
{
	char	end[4];

	end[0] = 27;
	end[1] = 91;
	end[2] = 70;
	end[3] = 0;
	if ((KEY_CODE_ALT_UP) && info->curs_y > info->orig_y)
	{
		tputs(tgetstr("up", NULL), 1, ft_putchar_err);
		info->curs_in_str -= info->col_nb;
	}
	else if ((KEY_CODE_ALT_DOWN) && info->s_len > info->col_nb)
	{
		if (info->s_len - info->curs_in_str >= info->col_nb)
		{
			tputs(tgetstr("sf", NULL), 1, ft_putchar_err);
			info->curs_in_str += info->col_nb;
		}
		else
			curs_extremity(info, end);
	}
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
}

void	get_key(int *loop, t_info *info)
{
	char	buff[5];

	(void)loop;
	ft_bzero(buff, 5);
	if ((read(0, buff, 4) < 0))
		exit(1);
	ioctl(0, TIOCGWINSZ, info->wndw);
	if (KEY_CODE_UP)
		(void)buff;
	else if (KEY_CODE_DOWN)
		(void)buff;
	else if (KEY_CODE_RIGHT)
		right_key(info);
	else if (KEY_CODE_LEFT)
		left_key(info);
	else if ((KEY_CODE_ALT_UP) || (KEY_CODE_ALT_DOWN))
		alt_up_down(info, buff);
	else if (KEY_CODE_BSP)
		del_char(info);
	else if ((KEY_CODE_HOME) || (KEY_CODE_END))
		curs_extremity(info, buff);
	else if (KEY_CODE_RC)
	{
		/*		*loop = 0;
				get_line(0, &(info->line));*/
		tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
		ft_printf("\n\n%s\n", info->line);
		/*	tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
			ft_printf("\n\n\nx: %d, y = %d, len = %d\n", info->curs_x,
			info->curs_y, info->s_len);
			tputs(tgetstr("rc", NULL), 1, ft_putchar_err);
			ft_printf("\nnb_lines: %d, nb_cols = %d, curs_in_str = %d\n%s\n",
			info->row_nb, info->col_nb, info->curs_in_str, info->line);
			tputs(tgetstr("rc", NULL), 1, ft_putchar_err);*/
	}
	else if (KEY_CODE_CTRL_D)
	{
		default_term_mode(info);
		exit(1);
	}
	else if (KEY_CODE_TAB)
		(void)buff;
	else if (ft_isprint(*buff))
		info->curs_in_str <= info->s_len ? insert_char(*buff, info)
			: add_char(*buff, info);
}
