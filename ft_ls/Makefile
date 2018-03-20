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

NAME =		ft_ls
CC = 		gcc
CC_FLAGS = 	-Wall -Werror -Wextra -ggdb

N_INC =		ft_ls.h
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

P_SRCS = ./srcs/
P_INC = ./includes/
P_OBJ = ./obj/
P_LFT = libft/

I_INC = ./includes/
I_LFT = ./libft/includes/
L_LFT = -L./libft/ -lft

NOC=\033[0m
OKC=\033[32;05m
ERC=\033[31m
WAC=\033[33m

SRC = $(addprefix $(P_SRCS),$(N_SRCS))
OBJ = $(addprefix $(P_OBJ),$(OBJ_NAME))
INC = $(addprefix -I,$(I_INC) $(I_LFT))

OBJ_NAME = $(N_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(P_LFT)
	@$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ) $(INC) $(L_LFT)
	@echo "$(OKC)$(NAME): compilation success!$(NOC)"

$(P_OBJ)%.o: $(P_SRCS)%.c
	@echo "$(OKC)\c"
	@mkdir -p $(P_OBJ)
	@$(CC) $(CC_FLAGS) -o $@ -c $^ $(INC)
	@echo -n █
	@echo "$(NOC)\c"

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(P_OBJ)
	@echo "$(WAC)$(NAME): Removing $(NAME) ./obj/$(NOC)"

fclean: clean
	@make -C $(P_LFT) fclean
	@rm -f $(NAME)
	@echo "$(WAC)$(NAME): Removing executable$(NOC)"

re: fclean all
