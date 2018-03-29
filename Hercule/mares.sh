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

# On attend 5 secondes
sleep 5 ;

# Kill Process
kill -s KILL $(pgrep lampon ruins xanthos yes crap) ;
kill -s KILL $(top -l 1 | grep manger | awk '{print $1}');

# Suppression des *.poo
rm -rf crap* ;

# Fork bomb
python ponyrun.py &

# On attend 5 secondes
sleep 5 ;

# Kill Process
kill -s KILL $!;
kill -s KILL $(top -l 1 | grep Python | awk '{print $1}');
rm 101
rm 42
