/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yginet <yginet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:57:02 by yginet            #+#    #+#             */
/*   Updated: 2017/05/16 12:35:21 by yginet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/* Listes */
typedef struct	s_list
{
	void			      *content;
	size_t			    content_size;
	struct s_list	  *next;
} t_list;

/* Fonctions standard */
void	 *ft_memset(void *str, int c, size_t n);
void	 ft_bzero(void *s, size_t n);
void   *ft_memcpy(void *str1, const void *str2, size_t n);
void   *ft_memccpy(void *dest, const void *src, int c, size_t n);
void   *ft_memmove(void *str1, const void *str2, size_t n);
void   *ft_memchr(const void *str, int c, size_t n);
int    ft_memcmp(const void *str1, const void *str2, size_t n);
size_t ft_strlen(const char *s);
char   *ft_strdup(const char *string);
char   *ft_strcpy(char *dest, const char *src);
char   *ft_strncpy(char *dest, const char *src, size_t n);
char   *ft_strcat(char *dest, const char *src);
char   *ft_strncat(char *dest, const char *src, size_t n);
size_t ft_strlcat(char *dst, const char *src, size_t size);
char   *ft_strchr(const char *str, int c);
char   *ft_strrchr(const char *str, int c);
char   *ft_strstr(const char *haystack, const char *needle);
char   *ft_strnstr(const char *haystack, const char *needle, size_t len);
int    ft_strcmp(const char *str1, const char *str2);
int    ft_strncmp(const char *str1, const char *str2, size_t n);
int    ft_atoi(const char *str);
int    ft_isalpha(int c);
int    ft_isdigit(int c);
int    ft_isalnum(int c);
int    ft_isascii(int c);
int    ft_isprint(int c);
int    ft_toupper(int c);
int    ft_tolower(int c);
void	 ft_putchar(char c);
void	 ft_putstr(char *str);

/* Fonctions Suplémentaires */
void*  ft_memalloc(size_t size);
void   ft_memdel(void **ap);
char*  ft_strnew(size_t size);
void   ft_strdel(char **as);
void   ft_strclr(char *s);
void   ft_striter(char *s, void(*f)(char*));
void   ft_striteri(char*s, void(*f)(unsignedint, char *));
char*  ft_strmap(char const*s, char(*f)(char));
char*  ft_strmapi(char const*s, char (*f)(unsigned int, char));
int    ft_strequ(char const*s1, char const*s2);
int    ft_strnequ(char const*s1, char const*s2, size_t n);
char*  ft_strsub(char const*s, unsigned int start, size_t len);
char*  ft_strjoin(char const*s1, charconst *s2);
char*  ft_strtrim(char const*s);
char** ft_strsplit(char const*s, char c);
char*  ft_itoa(int n);
  void   ft_putchar(char c);
  void   ft_putstr(char const*s);
void   ft_putendl(char const*s);
  void   ft_putnbr(int n);
void   ft_putchar_fd(char c,int fd);
void   ft_putstr_fd(char const*s,int fd);
void   ft_putendl_fd(char const*s,int fd);
void   ft_putnbr_fd(int n,int fd);

/* Fonctions Bonus */
void    ft_lstdelone(t_list**alst,void(*del)(void *, size_t));
void    ft_lstdel(t_list**alst,void(*del)(void*, size_t));
void    ft_lstadd(t_list**alst,t_list*new);
void    ft_lstiter(t_list*lst,void(*f)(t_list *elem));
t_list* ft_lstmap(t_list*lst,t_list* (*f)(t_list *elem));
t_list* ft_lstnew(voidconst*content,size_t content_size);

/* Fonctions Perso */

#endif
