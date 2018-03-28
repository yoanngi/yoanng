# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    mares.sh                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/28 14:33:58 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/28 16:42:50 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/bash

# Lancement du binaire
./manger &

# On attend 3 secondes
sleep 3 ;

# Kill Process
kill -s KILL $(pgrep lampon ruins xanthos yes crap) ;
kill -s KILL $(top -l 1 | grep manger | awk '{print $1}');

# Suppression des *.poo
rm -rf crap* ;

# Fork bomb
python fork.py &
