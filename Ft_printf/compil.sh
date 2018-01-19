# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    compil.sh                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/16 09:47:21 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/01/17 10:33:15 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

gcc -Wall -Wextra -Werror main.c Libft/libft.a ft_printf.c ft_printfargv.c ft_tab_argv.c ft_print_line_final.c ft_insert_word.c ft_delete_one_colun.c ft_size_tab.c ft_valid_argv.c ft_analyse_flag.c ft_argv_valid.c
