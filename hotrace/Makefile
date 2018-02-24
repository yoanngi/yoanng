# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/23 16:14:51 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2018/02/23 17:52:11 by xamartin    ###    #+. /#+    ###.fr      #
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
LIBFT = libft/*.c

SRCS = main.c\
	   ft_gnl.c\
	   ft_list_new.c\
	   ft_recupere_infos.c\
	   ft_resolve.c\
	   ft_whatdoyouwant.c\
	   ft_check_long.c


OBJS = $(SRCS:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INCLUDE) -o $(NAME)

./%.o:./%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
