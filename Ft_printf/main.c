/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 09:44:06 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 12:00:08 by yoginet     ###    #+. /#+    ###.fr     */
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

	printf("\n \033[0m [+] Basic test :\n");
	retv = printf("V: Hello Wolrd |%s| |%s| |%d|\n", "test1", "test2" , i);
	retc = ft_printf("C: Hello Wolrd |%s| |%s| |%d|\n", "test1", "test2" , i);
	if (retv == retc)
		printf("\033[32m Valeur de retour : V = %d || C = %d\n", retv, retc);
	else
		printf("\033[31m Valeur de retour : V = %d || C = %d\n", retv, retc);

	printf("\n \033[0m [+] Basic test 2 :\n");
	retv = printf("V: Hello Wolrd |%s| |%%t est |%d|\n", "test1", i);
	retc = ft_printf("C: Hello Wolrd |%s| |%%t est |%d|\n", "test1", i);
	if (retv == retc)
		printf("\033[32m Valeur de retour : V = %d || C = %d\n", retv, retc);
	else
		printf("\033[31m Valeur de retour : V = %d || C = %d\n", retv, retc);

	printf("\n \033[0m [+] Test modulo modulo :\n");
	retv = printf("V = %%\n");
	retc = ft_printf("C = %%\n");
	if (retv == retc)
		printf("\033[32m Valeur de retour : V = %d || C = %d\n", retv, retc);
	else
		printf("\033[31m Valeur de retour : V = %d || C = %d\n", retv, retc);

	printf("\n \033[0m [+] Test modulo modulo + string :\n");
	retv = printf("V = %% test\n");
	retc = ft_printf("C = %% test\n");
	if (retv == retc)
		printf("\033[32m Valeur de retour : V = %d || C = %d\n", retv, retc);
	else
		printf("\033[31m Valeur de retour : V = %d || C = %d\n", retv, retc);

	printf("\n \033[0m [+] basic hard test :\n");
	retv = printf("V: |%s| |%d|\n %d%%\n", "test1", i, 42);
	retc = ft_printf("C: |%s| |%d|\n %d%%\n", "test1", i, 42);
	if (retv == retc)
		printf("\033[32m Valeur de retour : V = %d || C = %d\n", retv, retc);
	else
		printf("\033[31m Valeur de retour : V = %d || C = %d\n", retv, retc);

	printf("Divers Test :\n");
	printf("%+d\n", i);
	printf("%+6d\n", i);
	printf("%+9d\n", i);
	printf("%+100d\n", i);
	printf("%-2d\n", i);
	return (0);
}
