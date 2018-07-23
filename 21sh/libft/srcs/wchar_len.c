/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wchar_len.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:42:36 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 14:50:59 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int	wchar_len(wchar_t c)
{
	int	len;

	len = 1;
	if (c <= 0x7FF && c >= 0x7F)
		len = 2;
	else if (c <= 0xFFFF && c >= 0x7F)
		len = 3;
	else if (c <= 0x1FFFFF && c >= 0x7F)
		len = 4;
	return (len);
}
