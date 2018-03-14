#!/bin/bash

# Projet Hercule Birds

NOC='\033[0m'
GREEN='\033[32;05m'
RED='\033[31m'
BLUE='\033[33m'

if [[ ("$1" == "-h" || "$1" == "--help") && $# == 1 ]] ; then
	echo -e "$GREEN""Welcome to Birds.sh$NOC";
	echo "usage :";
    echo "./birds [new] [name]";
	echo "After, choise the best options for you";
	echo "Enjoy !"
elif [[ ("$1" == "new") && $# == 2 ]] ; then
	sh scripts/new.sh $2
else
	echo "Enter no valide, please run this script with -h for wath usage";
fi ;
