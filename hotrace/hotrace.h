/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:22:56 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 15:21:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Libft/libft.h"

typedef struct		s_list
{
	char			*cle;
	char			*valeur;
	long			hash;
	long			compteur;
	struct s_list	*next;
}					t_list;

# define BUF_SIZE 32

#endif
