# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    birds.sh                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 10:36:25 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/03/15 12:05:05 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/bin/bash

# Projet Hercule Birds

NOC='\033[0m'
GREEN='\033[32;05m'
RED='\033[31m'
BLUE='\033[33m'

NAME=$2 ;
PATH_AV=$3 ;

if [[ ("$1" == "-new" || "$1" == "-n") && $# == 3 ]] ; then
	sh scripts/new.sh $NAME $PATH_AV ;
elif [[ ("$1" == "-delete" || "$1" == "-d") && $# == 2 ]] ; then
	echo "$RED""Mode Delete -> tape y for confirm delete$NOC" ;
	rm -rfi $2 ;
elif [[ ("$1" == "-help" || "$1" == "-h") && $# == 1 ]] ; then
	echo "$GREEN""MAN birds.sh$NOC" ;
	echo "usage :" ;
	echo "$GREEN./birds -new [name] [PATH]$NOC";
	echo "For create directory" ;
	echo "You chose the type of your projecti (C, py, sh ...)" ;
	echo "if your chose is C, you create automatly the directory for srcs, includes, Makefile .. ans can import your libft" ;
	echo "You chose if you want a autor file" ;
	echo "You chose if you want a .gitignore file" ;
	echo "$GREEN./birds -delete [PATH]$NOC";
	echo "For delete the directory with confirm" ;
else
	echo "$GREEN""Welcome to Birds.sh$NOC";
	echo "usage :";
	echo "./birds -h for more informations";
	echo "./birds -new [name] [PATH]";
	echo "./birds -delete [PATH]";
	echo "After, chose the best options for you";
	echo "Enjoy !"
fi ;
