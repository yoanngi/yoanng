# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/23 16:14:51 by xamartin     #+#   ##    ##    #+#        #
<<<<<<< HEAD
#    Updated: 2018/02/24 14:37:03 by yoginet     ###    #+. /#+    ###.fr      #
=======
#    Updated: 2018/02/23 17:52:11 by xamartin    ###    #+. /#+    ###.fr      #
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY = all, clean, fclean, re

NAME = hotrace

#COMIPLATION

CC = gcc

CFLAGS 		= -Wall -Wextra -Werror

#PATH

INCLUDE = hotrace.h

SRCS = main.c\
	   ft_gnl.c\
	   ft_list_new.c\
	   ft_recupere_infos.c\
	   ft_whatdoyouwant.c\
<<<<<<< HEAD
	   ft_malloc_tab.c\
	   ft_putstr.c\
	   ft_strsub.c\
	   ft_strdup.c\
	   ft_strcmp.c\
	   ft_memcpy.c\
	   ft_strlen.c\
	   ft_strdel.c\
	   ft_strnew.c\
	   ft_putchar.c\
	   ft_strcpy.c\
	   ft_strchr.c\
	   ft_memset.c\
=======
	   ft_check_long.c
>>>>>>> 123b871fa5a52f9b41a3cd9985a2e876316cfca6


OBJS = $(SRCS:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME)

./%.o:./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
