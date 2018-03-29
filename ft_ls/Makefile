# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/29 13:47:20 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NOCOLOR=\033[0m
VERT=\033[32;05m
JAUNE=\033[33m

NAME =		ft_ls
CC = 		gcc
FLAGS = 	-Wall -Werror -Wextra
DEL =		rm -rf

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = -I $(INC_PATH) -I $(LIB_PATH)includes/

OBJ_NAME = $(N_SRCS:.c=.o)

N_SRCS = 	ft_error.c\
			ft_ls.c\
			ft_ls_simple.c\
			ft_check_options.c\
			ft_add_list.c\
			ft_clean_list.c\
			ft_print.c\
			ft_options_r.c\
			ft_get_infos.c\
			ft_get_infos_suite.c\
			ft_check_space.c\
			ft_return_l.c\
			ft_file.c\
			ft_file_suite.c\
			ft_ls_liste.c\
			ft_print_suite.c\
			ft_valid_options.c\
			ft_class.c\
			ft_class_repertory.c\
			ft_display.c\
			ft_display_suite.c\
			ft_minor_major.c\
			ft_print_block.c\
			main.c\

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -L$(LIB_PATH) -lft -o $(NAME)
	@echo "$(VERT)$(NAME): compilation success!$(NOCOLOR)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(VERT)\c"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(FLAGS) $(INC) -o $@ $<
	@echo -n █
	@echo "$(NOCOLOR)\c"

clean:
	@make -C $(LIB_PATH) clean
	@$(DEL) $(OBJ_PATH)
	@echo "$(JAUNE)$(NAME): Removing $(NAME) ./obj/$(NOCOLOR)"

fclean: clean
	@make -C $(LIB_PATH) fclean
	@$(DEL) $(NAME)
	@echo "$(JAUNE)$(NAME): Removing executable$(NOC)"

re: fclean all
