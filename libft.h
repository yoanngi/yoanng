/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoannginet <yginet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:57:02 by yginet            #+#    #+#             */
/*   Updated: 2017/05/16 12:35:21 by yoanngin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/* Fonctions standard */

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void  *ft_memcpy(void *str1, const void *str2, size_t n);
void  *ft_memccpy(void *dest, const void *src, int c, size_t n);
void  *ft_memmove(void *str1, const void *str2, size_t n);
void *ft_memchr(const void *str, int c, size_t n);
int   ft_memcmp(const void *str1, const void *str2, size_t n);
size_t  ft_strlen(const char *s);
char  *strdup(const char *string);
char  *ft_strcpy(char *dest, const char *src);
char  *ft_strncpy(char *dest, const char *src, size_t n);
char  *strcat(char *dest, const char *src);
char  *strncat(char *dest, const char *src, size_t n);
/*
strlcat
strchr
strrchr */
char   *ft_strstr(const char *haystack, const char *needle);
char   *ft_strnstr(const char *haystack, const char *needle, size_t len);
int   ft_strcmp(const char *str1, const char *str2);
int   ft_strncmp(const char *str1, const char *str2, size_t n);
int   ft_atoi(const char *str);
/* isalpha
isdigit
isalnum
isascii
isprint
toupper
tolower */
void	ft_putchar(char c);
void	ft_putstr(char *str);

/* Fonctions Suplémentaire */

#endif
