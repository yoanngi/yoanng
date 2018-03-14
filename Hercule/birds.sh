#!/bin/bash

# Projet Hercule Birds

if [[ ("$1" == "-h" || "$1" == "--help") && $# == 1 ]] ; then
	echo "This scripts create or delete your project";
    echo "./birds [new] OR [delete] [name]";
	echo "After, choise the best options for you";
	echo "Enjoy !"
elif [[ ("$1" == "new") && $# == 2 ]] ; then
	sh scripts/new.sh $2
elif [[ ("$1" == "delete") && $# == 2 ]] ; then
	sh scripts/delete.sh $2
else
	echo "options no valide, please run this script with -h for usage";
fi ;
