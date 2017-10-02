/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofayard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 17:43:26 by jofayard          #+#    #+#             */
/*   Updated: 2017/09/18 20:59:13 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		testline(int line, int nb, int **tab)
{
	int compt;

	compt = 0;
	while (compt < 9)
	{
		if (tab[line][compt] == nb)
			return (0);
		compt++;
	}
	return (1);
}

int		testcol(int nb, int col, int **tab)
{
	int compt;

	compt = 0;
	while (compt < 9)
	{
		if (tab[compt][col] == nb)
			return (0);
		compt++;
	}
	return (1);
}

int		testblock(int nb, int line, int col, int **tab)
{
	int l_tmp;
	int c_tmp;

	l_tmp = 3 * (line / 3);
	c_tmp = 3 * (col / 3);
	line = l_tmp;
	while (line < l_tmp + 3)
	{
		col = c_tmp;
		while (col < c_tmp + 3)
		{
			if (tab[line][col] == nb)
				return (0);
			col++;
		}
		line++;
	}
	return (1);
}

int		backtracking(int **tab, int pos)
{
	int line;
	int col;
	int compt;

	compt = 1;
	line = pos / 9;
	col = pos % 9;
	if (pos == 9 * 9)
		return (1);
	if (tab[line][col] != 0)
		return (backtracking(tab, pos + 1));
	while (compt <= 9)
	{
		if (testline(line, compt, tab) == 1 && testcol(compt, col, tab) == 1
			&& testblock(compt, line, col, tab) == 1)
		{
			tab[line][col] = compt;
			if (backtracking(tab, pos + 1) == 1)
				return (1);
		}
		compt++;
	}
	tab[line][col] = 0;
	return (0);
}
