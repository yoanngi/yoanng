# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/04/21 15:53:09 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NOCOLOR=\033[0m
VERT=\033[32;05m
JAUNE=\033[33m

NAME =		minishell
CC = 		gcc
FLAGS = 	-Wall -Werror -Wextra
DEL =		rm -rf

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH), $(N_SRCS:.c=.o))
INC = -I $(INC_PATH) -I $(LIB_PATH)includes/

N_SRCS = 	main.c\
			ft_error.c\
			core_minishell.c\
			func_signal.c\
			ft_struct.c\
			ft_fork.c\
			format_line.c\
			func_spe.c\
			func_access.c\
			various_func.c\
			ft_enclosing.c\
			good_func.c\
			func_cd.c\
			builtins/func_echo.c\
			builtins/func_echo_suite.c\
			builtins/func_echo_print.c\
			builtins/func_env.c\
			builtins/func_setenv.c\
			builtins/func_unsetenv.c\

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -L$(LIB_PATH) -lft -o $(NAME)
	@echo "$(VERT)$(NAME): compilation success!$(NOCOLOR)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(VERT)\c"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/builtins
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
