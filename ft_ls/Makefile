# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/20 13:31:36 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

NAME =		ft_ls
CC = 		gcc
FLAGS = 	-Wall -Werror -Wextra

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
			ft_display.c\
			ft_minor_major.c\
			ft_print_block.c\
			main.c\

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -L $(LIB_PATH) -lft -o $(NAME)
	@echo "$(OKC)$(NAME): compilation success!$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(OKC)\c"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAGS) -o $@ -c $^ $(INC)
	@echo -n █
	@echo "$(NOC)\c"

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)$(NAME): Removing $(NAME) ./obj/$(NOC)"

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): Removing executable$(NOC)"

re: fclean all
