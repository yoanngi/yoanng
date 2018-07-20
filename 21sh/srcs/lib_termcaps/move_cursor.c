/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_cursor.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 11:18:44 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 18:06:47 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

/*
** LEFT KEY
** le : move cursor left
** up : move cursor up
** vi / ve : init/end cursor invisibility
*/

void	left_key(t_info *info)
{
	if (info->s_len)
	{
		if (info->curs_x == 1 && info->curs_y > info->orig_y)
		{
			tputs(tgetstr("up", NULL), 1, ft_putchar_err);
			while (info->curs_x <= info->col_nb)
			{
				tputs(tgetstr("nd", NULL), 0, ft_putchar_err);
				info->curs_x++;
			}
			info->curs_in_str--;
		}
		else if (info->curs_in_str > 1)
		{
			tputs(tgetstr("le", NULL), 1, ft_putchar_err);
			info->curs_in_str--;
		}
	}
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
}

/*
** RIGHT KEY
** nd : move cursor right
** le : move cursor left
** sr : scroll the screen one line down
** sf : scroll one line up
*/

void	right_key(t_info *info)
{

//	ft_printf("\n\n %d\n", info->curs_in_str);
	if (info->curs_in_str <= info->s_len)
	{
		if (info->curs_x < info->col_nb)
		{
			info->curs_in_str++;
			tputs(tgetstr("nd", NULL), 0, ft_putchar_err);
		}
		else if (info->curs_x == info->col_nb)
		{
			tputs(tgetstr("sf", NULL), 0, ft_putchar_err);
			while (info->curs_x > 1)
			{
				tputs(tgetstr("le", NULL), 0, ft_putchar_err);
				info->curs_x--;
			}
			info->curs_in_str++;
		}
	}
	info->curs_x = CURS_X;
	info->curs_y = CURS_Y;
}

/*
** Put cursor at first (HOME) or last (END) position
*/

void	curs_extremity(t_info *info, char *buff)
{
	tputs(tgetstr("vi", NULL), 1, ft_putchar_err);
	if (KEY_CODE_HOME)
	{
		if (info->s_len + ft_strlen(info->prmpt) > info->col_nb * info->row_nb)
		{
		}
		else
			while (info->curs_in_str > 1)
				left_key(info);
		info->curs_x = CURS_X;
		info->curs_y = CURS_Y;
		info->curs_in_str = 1;
	}
	else if (KEY_CODE_END)
	{
		while (info->curs_in_str <= info->s_len)
			right_key(info);
		info->curs_x = CURS_X;
		info->curs_y = CURS_Y;
		info->curs_in_str = info->s_len + 1;
	}
	tputs(tgetstr("ve", NULL), 1, ft_putchar_err);
}
