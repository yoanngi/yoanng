# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    mares.sh                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/28 14:33:58 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/28 14:44:50 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/bash

# Lancement du binaire
./manger &

# On attend 2 secondes
sleep 2

# Kill Process
kill -SIGKILL $!

# Suppression des *.poo
rm -rf crap*

# Recuperation des canassons

