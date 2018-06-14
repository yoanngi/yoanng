/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keys.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 14:39:02 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 19:54:44 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	right_key(int *curs_idx, char *line)
{

	if (line && ft_strlen(line) && *curs_idx < ft_strlen(line))
	{
		tputs(tgetstr("nd", NULL), 0, ft_putchar_err);
		*curs_idx += 1;
	}
}

void	left_key(int *curs_idx)
{
	if (*curs_idx)
	{
		tputs(tgetstr("le", NULL), 1, ft_putchar_err);
		*curs_idx -= 1 ;
	}
}

void	insert_char(char c, int *curs_idx)
{
	tputs(tgetstr("im", NULL), 1, ft_putchar_err);
	ft_putchar(c);
	*curs_idx += 1;
	tputs(tgetstr("ei", NULL), 1, ft_putchar_err);
}

char	*get_key(int *loop, char *line, int *curs_idx)
{
	char		buff[5];

	ft_bzero(buff, 5);
	if ((read(0, buff, 4) < 0))
		exit(1);
	//	ft_printf("curs idx = %d\n", curs_idx);
	if (KEY_CODE_UP)
		(void)buff;
	else if (KEY_CODE_DOWN)
		(void)buff;
	else if (KEY_CODE_RIGHT)
		right_key(curs_idx, line);
	else if (KEY_CODE_LEFT)
		left_key(curs_idx);
	else if (KEY_CODE_BSP)
		(void)buff;
	else if (KEY_CODE_RC)
		*loop = 0;
	else if (KEY_CODE_CTRL_D)
		exit(1);
	else if (KEY_CODE_TAB)
		(void)buff;
	else
		insert_char(*buff, curs_idx);
	return (line);
}
