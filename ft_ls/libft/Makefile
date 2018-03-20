# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2017/11/24 10:04:53 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

NOC=\033[0m
OKC=\033[94;1m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC = $(addprefix $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME += libft.h

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
		 	@echo "$(OKC)\nlibft: Creating $(NAME): \c"
		 	@ar rc $(NAME) $(OBJ)
		 	@echo "$(OKC)OK. \c"
		 	@echo "$(OKC)Generating index$(NOC): \c"
		 	@ranlib $(NAME)
		 	@echo "$(OKC)OK.\nlibft: compilation success!$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		 	@echo "$(OKC)\c"
		 	@mkdir -p $(OBJ_PATH)
		 	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
		 	@echo -n █
		 	@echo "$(NOC)\c"

clean:
		 	@echo "$(WAC)libft: Removing libft ./obj/$(NOC)"
		 	@rm -rf $(OBJ_PATH)

fclean: clean
		 	@echo "$(WAC)libft: Removing $(NAME)$(NOC)"
		 	@rm -f $(NAME)
		 	@rm -rf $(OBJ_PATH)

re: fclean all
