# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/01/17 11:45:56 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_printf

HEADER = ft_printf.h

CC = gcc

CFLAGS += -Wall -Wextra -Werror

SRCS = ft_argv_valid.c \
	   ft_parse.c \
	   ft_printf.c \
	   ft_tab_argv.c \
	   main.c \

.PHONY: all clean fclean re

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	cd Libft && Make clean && cd ../
	$(AR) -rc $(NAME) $(OBJS) $(HEADER)
#	$(CC) $(CFLAGS) $(OBJS) Libft/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	@gcc -c $< -o $@

