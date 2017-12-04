# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/25 12:49:36 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2017/12/01 14:42:18 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

HEADER = fillit.h

CFLAGS += -Wall -Wextra -Werror

CC = gcc

SRCS = ft_strlen.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_resolve.c \
	   ft_convert_str.c \
	   ft_count_word.c \
	   ft_strsplit.c \
	   ft_strsub.c \
	   ft_lstnew.c \
	   ft_resize_str.c \
	   compact.c \
	   ft_check_list.c \
	   ft_lstcount.c \
	   ft_convert_lettre.c \
	   ft_piece_valide.c \
	   main.c \
	   ft_algo_tetra.c \
	   ft_place.c \
	   ft_print_carre.c \
	   ft_remplissage_tab.c \
	   ft_malloc_tab.c \
	   ft_compact_unit.c \
	   ft_memcpy.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	@gcc -c $< -o $@
