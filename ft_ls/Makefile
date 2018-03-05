# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/01 13:14:22 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME =		ft_ls
CC =		gcc
RM =		rm -f
FLAGS =		-Wall -Wextra -Werror

INC =		includes/
LIBFT =		libft/ 

SOURCES = 	srcs/ft_error.c\
			srcs/ft_ls.c\
			srcs/ft_ls_simple.c\
			srcs/ft_check_options.c\
			srcs/ft_add_list.c\
			srcs/ft_print.c\
			srcs/ft_options_r.c\
			srcs/ft_get_infos.c\
			srcs/ft_get_infos_suite.c\
			srcs/ft_check_space.c\
			srcs/ft_return_l.c\
			srcs/ft_file.c\
			srcs/ft_ls_liste.c\
			srcs/ft_print_suite.c\
			srcs/ft_valid_options.c\
			srcs/ft_class.c\
			srcs/main.c\

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L $(LIBFT) -lft

%.o: %.c
		$(CC) $(FLAGS) -I $(INC) $< -c -o $@

clean:
	@make clean -C $(LIBFT)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all
