# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    mares.sh                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/28 14:33:58 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/29 10:53:10 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/bash

# Lancement du binaire
./manger &

# On attend 5 secondes
sleep 5 ;

# Kill Process
kill -s ABRT $(pgrep lampon ruins xanthos yes crap) ;
kill -s ABRT $(top -l 1 | grep manger | awk '{print $1}');

# Suppression des *.poo
rm -rf crap* ;

# On relance nos canasson
python ponyrun.py &

# On attend 5 secondes
sleep 5 ;

# Kill Process
kill -s KILL $!;
kill -s KILL $(top -l 1 | grep Python | grep -v "71" | awk '{print $1}');
pkill yes;

# On delete les fichiers creer
rm 101
rm 4
kill -s KILL $!;

