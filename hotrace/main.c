/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:18:46 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 14:22:49 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "hotrace.h"

int		main(void)
{
	if (!ft_recupere_infos())
	{
		ft_putstr("Usage : ./hotrace\n");
		ft_putstr("Element a rechercher : [Enter your elements]\n");
		ft_putstr("Dans quoi rechercher : [Enter your elements]\n");
	}
	return (0);
}
