/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:57:08 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 13:41:59 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Etape 1 : On verifie le Nombre d'argument
** Etape 2 : On appel la fonction ft_resolve, qui elle meme appel ft_convert_str
**			 ft_convert_str transforme ce qu'on lit dans le fichier en une
**			 unique chaine.
** Etape 3 : On fait une premiere verif concernant la longueur de la chaine, que
**			 les carateres contenu dedant soit valide et les retours a la ligne.
**			 ATTENTION : le dernier tetriminos n'est pas check, des tests de
**			 verif son a faire.
** Etape 4 : On insert chaque tetriminos dans une liste chainer:
**			 content = La partie de la chaine correspondant au tetriminos
**			 Utilisation de strsub.
**			 On redimentionne notre chaine au fur et a meusure.
** Etape 5 : On boucle notre liste chainer pour remplir la variable block
**			 initialiser a NULL (ft_check_list), ensuite notre tableau 2D est
**			 compacter (ft_compact).
** Etape 6 : On compare notre liste chainer avec des tetras valide.
*/

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage : fillit <target files>\n");
		return (1);
	}
	ft_resolve(argv[1]);
	return (0);
}
