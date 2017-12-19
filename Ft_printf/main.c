/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 09:44:06 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 14:55:01 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;

	i = 48;
	ft_printf("\n[+]-------------------------------------------->		Basic test :\n");
	printf("V: Hello Wolrd |%s| |%s| |%d| \n", "test1", "test2" , i);
	ft_printf("C: Hello Wolrd |%s| |%s| |%d| \n", "test1", "test2" , i);
	ft_printf("\n[+]----------------------------------------->	Test modulo modulo :\n");
	printf("V = %%\n");
	ft_printf("C = %%\n");
	ft_printf("\n[+]--------------------------------->	Test modulo modulo + string :\n");
	printf("V = %% test\n");
	ft_printf("C = %% test\n");
	return (0);
}
