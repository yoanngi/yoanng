/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 09:44:06 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 10:28:32 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;

	i = 48;
	ft_printf("Hello Wolrd |%s| |%s| |%d| \n", "test1", "test2", i);
/*	printf("Test printf\n");
	printf("valeur avec modulo s : %s \n", "test");
	printf("valeur avec modulo d : %d \n", i);
	printf("valeur avec modulo S : %S \n", "test");
	printf("valeur avec modulo D : %D \n", i);*/
	return (0);
}
