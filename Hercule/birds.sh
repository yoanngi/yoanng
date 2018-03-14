#!/bin/bash

# Projet Hercule Birds

if [[ ("$1" == "-h" || "$1" == "--help") && $# == 1 ]] ; then
	echo "This scripts create or delete your project";
    echo "./birds [new] OR [delete] [name]";
	echo "After, choise the best options for you";
	echo "Enjoy !"
else if [[ ("$1" == "new") && $# == 2 ]] ; then
	sh new.sh
else if [[ ("$1" == "delete") && $# == 2 ]] ; then
	sh delete.sh
else
	echo "options no valide, please run this script with -h for usage";

