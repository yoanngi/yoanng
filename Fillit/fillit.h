/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 14:00:10 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 15:55:16 by yoginet          ###   ########.fr       */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 1

/*
** list
*/
typedef struct	s_list
{
	char			*content;
	char			content_size;
	char			**block;
	struct s_list	*next;

}				t_list;

/*
** Fonctions
*/
void			ft_putstr(const char *str);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_putchar(int c);
void			ft_resolve(char *doc);
char			*ft_convert_str(char *doc);
size_t			ft_strlen(const char *s);
char			**ft_strsplit(const char *s, char c);
size_t			ft_count_word(const char *s, char c);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
t_list			*ft_lstnew(void const *content, size_t content_size);
char			*ft_resize_str(char *str, size_t len);
t_list			*ft_compact(t_list *s);
void			ft_check_list(t_list *lst);
void			ft_print_list(t_list *lst);
size_t			ft_lstcount(t_list *lst);
void			ft_algo_tetra(t_list *lst, int i);
int				ft_piece_valide(char **s, int pos);
void			ft_convert_lettre(char **s, char c);
int				ft_place_one(char **tab, t_list *lst, int l, int p);
void			ft_print_carre(char **tab, int len);
char			**ft_remplissage_tab(char **tab, int l, char c);
char			**ft_malloc_tab(char **tab, int len);
void			ft_compact_unit(const char *s);

#endif
