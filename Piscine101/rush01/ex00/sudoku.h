/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 08:26:15 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/18 18:19:13 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_resolv(char **argv);
void	ft_print_tab(int **tab);
int		ft_check_sudoku(char *argv);
int		ft_check_max(char *argv);
int		ft_atoi(char *str);
int		backtracking(int **tab, int pos);
int		backtracking_verif(int **tab, int pos);
int		testline(int line, int nb, int **tab);
int		testcol(int nb, int col, int **tab);
int		testblock(int nb, int line, int col, int **tab);

#endif
