/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:22:56 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 16:36:04 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"

# include <stdio.h>

# define BUFF_SIZE 32

typedef struct		s_lst
{
	char			*cle;
	char			*valeur;
	long			hash;
	long			compteur;
	struct s_lst	*collision;
	struct s_lst	*next;
}					t_lst;

t_lst				*ft_list_new(void);
int					get_next_line(int fd, char **line);
long				ft_hash(char *cle);
void				ft_add_infos(char **line, char **cpy, t_lst **list, int nb);
int					ft_recupere_infos(void);
void				ft_collision(t_lst *data, unsigned long **tab, int hash);
unsigned long		**ft_insert(unsigned long **tab, t_lst *cpy);
unsigned long		**ft_malloc_tab(unsigned long **tab, int i, int nb);
int					ft_resolve(t_lst *start, int i);
void				ft_existe(char **line, unsigned long **tab);
void				ft_whatdoyouwant(unsigned long **tab);
int					ft_check_long(int i, t_lst *start);
int					ft_hereornot(char **line, t_lst **data);

#endif
