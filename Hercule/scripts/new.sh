#!/bin/bash

# Projet Hercule Birds
# http://blog.inforeseau.com/2010/11/ecrire-script-bash-interactif-avec-saisie-par-lutilisateur


NAME="$1"

# Intro
echo "Welcome to birds scripts";
echo "Creating Project $1";
until [[ ${confirm} =~ ^[0-1]+$ ]]; do
    echo "Please confirme this name of project [0 = NO // 1 = YES]";
    read confirm
done

if [[ ("$confirm" == "0")]] ; then
    while [ -z ${newname[$1]} ]; do
        echo "Please enter the new name or exit (-q)";
        read newname[$1]
        if [[ ("$newname" == "-q" && $# == 1) ]] ; then
            echo "Exit Project";
            exit ;
        else
            NAME="$newname"

        fi ;
    done
fi ;

# Name ok, verify if directory exist
if [ -e "$NAME" ] ; then
    echo "Warning, the directory exist !" ;
    echo "Please change this name or delete directory" ;
    exit ;
else
    echo "Create project $NAME" ;
    mkdir $NAME ;
    echo "Creating Successful !" ;
fi ;

# What this language ?
while [ -z ${language[$1]} ]; do
    echo "What the language use ?";
    read language[$1]
    if [[ ("$language" == "C" || "$language" == "c") && $# == 1 ]] ; then
        echo "Create directory :";
        echo "$NAME/srcs";
        mkdir $NAME/srcs ;
        echo "$NAME/includes";
        mkdir $NAME/includes ;
        echo "Create Makefile :";
        sh scripts/generate_Makefile.sh ;
        echo "Success" ;
    else
        echo "Directory Create, Good luck for your project !"
    fi ;
done ;

# Want author ?
while [ -z ${autor[$1]} ]; do
    echo "You want the autor file ? (n = No, else give your login)";
    read autor[$1]
    if [[ ("$autor" == "N" || "$autor" == "n") && $# == 1 ]] ; then
        echo "No autor create" ;
    else
        echo "Create autor file ....." ;
        echo "$2" > $NAME/autor ;
        echo "Success" ;
    fi ;
done ;

# Want gitignore ?
while [ -z ${git[$1]} ]; do
    echo "You want the .gitignore? (n = N0, y = YES)";
    read git[$1]
    if [[ ("$git" == "N" || "$git" == "n") && $# == 1 ]] ; then
        echo "No .gittignore" ;
    else
        echo "Create .gitignore file ....." ;
        echo "Success" ;
    fi ;
done ;