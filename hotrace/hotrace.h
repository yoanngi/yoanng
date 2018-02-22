/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:22:56 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 16:22:33 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_lst
{
	char			*cle;
	char			*valeur;
	long			hash;
	long			compteur;
	struct s_lst	*next;
}					t_lst;

t_lst				*ft_list_new(void);
int					get_next_line(int fd, char **line);
int					ft_resolve(t_lst *start, int i);
int					ft_recupere_infos(void);

#endif
