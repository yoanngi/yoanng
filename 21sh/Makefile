# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <yoginet@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 10:04:43 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/06/04 11:13:18 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NOCOLOR=\033[0m
VERT=\033[32;05m
JAUNE=\033[33m

NAME =		21sh
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
			core_minishell.c\
			format_line.c\
			ft_fork.c\
			func_signal.c\
			ft_check_cmd.c\
			clear_line.c\
			ft_split_separator.c\
			lib_minishell/ft_add_line.c\
			lib_minishell/ft_del_tab.c\
			lib_minishell/ft_duplicate_tab.c\
			lib_minishell/ft_insert_in_tab.c\
			lib_minishell/ft_print_tab.c\
			lib_minishell/ft_dir_exist.c\
			lib_minishell/ft_len_tab.c\
			lib_minishell/display.c\
			lib_minishell/func_access.c\
			lib_minishell/ft_error.c\
			lib_minishell/ft_check_path.c\
			lib_minishell/ft_good_path.c\
			lib_minishell/ft_return_path.c\
			lib_minishell/ft_insert_tild.c\
			lib_minishell/ft_insert_dollar.c\
			lib_minishell/ft_existe_in_path.c\
			init/ft_struct.c\
			init/ft_struct_null.c\
			init/ft_delete_struct.c\
			init/ft_init_builtins.c\
			builtins/good_func.c\
			builtins/func_cd.c\
			builtins/func_cd_suite.c\
			builtins/func_echo.c\
			builtins/func_echo_suite.c\
			builtins/func_echo_print.c\
			builtins/func_env.c\
			builtins/func_env_suite.c\
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
	@mkdir -p $(OBJ_PATH)/init
	@mkdir -p $(OBJ_PATH)/lib_minishell
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
