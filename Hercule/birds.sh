#!/bin/bash

# Projet Hercule Birds

NOC='\033[0m'
GREEN='\033[32;05m'
RED='\033[31m'
BLUE='\033[33m'

NAME=$2 ;
PATH_AV=$3 ;

if [[ ("$1" == "-new") && $# == 3 ]] ; then
	sh scripts/new.sh $NAME $PATH_AV ;
elif [[ ("$1" == "-delete") && $# == 3 ]] ; then
	sh scripts/delete.sh $NAME $PATH_AV;
else
	echo -e "$GREEN""Welcome to Birds.sh$NOC";
	echo "usage :";
    echo "./birds [-new, -delete] [name] [PATH]";
	echo "After, choise the best options for you";
	echo "Enjoy !"
fi ;
