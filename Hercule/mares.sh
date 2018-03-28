# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    mares.sh                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/28 14:33:58 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/28 15:26:30 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/bash

# Lancement du binaire
./manger &

# On attend 2 secondes
sleep 3

# Kill Process
kill -s KILL $(pgrep deinos podargos ruins lampon xanthos plop)
kill -9 $!

# Suppression des *.poo
rm -rf crap*

# Recuperation des canassons

