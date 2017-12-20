/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 09:44:06 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:13:13 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int i;
	int retv;
	int retc;

	i = 48;
	ft_printf("\n[+]-------------------------------------------->		Basic test :\n");
	retv = printf("V: Hello Wolrd |%s| |%s| |%d|\n", "test1", "test2" , i);
	retc = ft_printf("C: Hello Wolrd |%s| |%s| |%d|\n", "test1", "test2" , i);
	printf("Valeur de retour : V = %d || C = %d\n", retv, retc);
	ft_printf("\n[+]-------------------------------------------->		Basic test 2 :\n");
	retv = printf("V: Hello Wolrd |%s| |%%t est |%d|\n", "test1", i);
	retc = ft_printf("C: Hello Wolrd |%s| |%%t est |%d|\n", "test1", i);
	printf("Valeur de retour : V = %d || C = %d\n", retv, retc);
	ft_printf("\n[+]----------------------------------------->	Test modulo modulo :\n");
	retv = printf("V = %%\n");
	retc = ft_printf("C = %%\n");
	printf("Valeur de retour : V = %d || C = %d\n", retv, retc);
	ft_printf("\n[+]--------------------------------->	Test modulo modulo + string :\n");
	retv = printf("V = %% test\n");
	retc = ft_printf("C = %% test\n");
	printf("Valeur de retour : V = %d || C = %d\n", retv, retc);
	return (0);
}
