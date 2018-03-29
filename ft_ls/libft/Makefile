# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/29 13:47:55 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NOCOLOR=\033[0m
VERT=\033[32;05m
JAUNE=\033[33m

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = -I $(INC_PATH)

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NAME =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strrev.c \
			ft_count_word.c \
			ft_print_bits.c \
			ft_isupper.c \
			ft_islower.c \

all: $(NAME)

$(NAME): $(OBJ)
		 	@ar rc $(NAME) $(OBJ)
		 	@ranlib $(NAME)
		 	@echo "$(VERT)OK.\nlibft: compilation success!$(NOCOLOR)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		 	@echo "$(VERT)\c"
		 	@mkdir -p $(OBJ_PATH)
		 	@$(CC) $(FLAGS) -o $@ -c $^ $(INC)
		 	@echo -n █
		 	@echo "$(NOCOLOR)\c"

clean:
		 	@echo "$(JAUNE)libft: Removing libft ./obj/$(NOCOLOR)"
		 	@rm -rf $(OBJ_PATH)

fclean: clean
		 	@echo "$(JAUNE)libft: Removing $(NAME)$(NOCOLOR)"
		 	@rm -f $(NAME)

re: fclean all
