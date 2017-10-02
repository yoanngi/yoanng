# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoginet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 08:48:18 by yoginet           #+#    #+#              #
#    Updated: 2017/09/19 09:26:18 by yoginet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putstr.c ft_putchar.c ft_strlen.c ft_swap.c ft_strcmp.c
ar rc libft.a ft_putstr.o ft_putchar.o ft_strlen.o ft_swap.o ft_strcmp.o
rm ft_putstr.o ft_putchar.o ft_strlen.o ft_swap.o ft_strcmp.o
ranlib libft.a
