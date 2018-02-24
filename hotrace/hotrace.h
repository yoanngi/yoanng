/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hotrace.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/22 14:22:56 by yoginet      #+#   ##    ##    #+#       */
<<<<<<< HEAD
/*   Updated: 2018/02/24 14:34:19 by yoginet     ###    #+. /#+    ###.fr     */
=======
/*   Updated: 2018/02/23 17:51:51 by xamartin    ###    #+. /#+    ###.fr     */
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
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
#include <fcntl.h>

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
<<<<<<< HEAD
unsigned long		**ft_malloc_tab(unsigned long **tab, int i, int nb);
int					ft_recupere_infos(unsigned long **tab);
void				ft_add_infos(char **line, char **cpy, unsigned long **tab);
long				ft_hash(char *cle);
void				ft_whatdoyouwant(unsigned long **tab);
void				ft_existe(char **line, unsigned long **tab);
char				*ft_strchr(const char *s, int c);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_putstr(const char *str);
int					ft_putchar(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memset(void *str, int c, size_t n);
=======
//int					ft_resolve(t_lst *start, int i);
//int					ft_recupere_infos(void);
long				ft_hash(char *cle);
char				*ft_itoa_base(long n, int base);
void				ft_whatdoyouwant(unsigned long **tab);
void				ft_existe(char **line, unsigned long **tab);
void				ft_test_acces(unsigned long **tab, int hash);
int					ft_check_long(int i, t_lst *start);
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6

unsigned long		**ft_malloc_tab(unsigned long **tab, int i, int nb);
unsigned long		**ft_insert(unsigned long **tab, t_lst *cpy);
int					ft_recupere_infos(unsigned long **tab);
int					ft_resolve_opti(t_lst **start, unsigned long **tab);
#endif
