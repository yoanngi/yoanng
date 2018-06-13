/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 12:15:32 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/13 15:54:58 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	raw_term_mode(void)
{
	char			*term_name;
	struct termios	term;

	term_name = getenv("TERM");
	tcgetattr(STDIN_FILENO, &term);
	if (tgetent(NULL, term_name) < 1)
		exit(1);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_oflag &= ~(OPOST);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	tputs(tgetstr("sc", NULL), 0, ft_putchar_err);
}

void	default_term_mode(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ECHO | ICANON);
	term.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	tputs(tgetstr("rc", NULL), 0, ft_putchar_err);

}
