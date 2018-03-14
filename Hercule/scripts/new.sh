#!/bin/bash

# Projet Hercule Birds
# http://blog.inforeseau.com/2010/11/ecrire-script-bash-interactif-avec-saisie-par-lutilisateur

NOC='\033[0m'
GREEN='\033[32;05m'
RED='\033[31m'
SUR='\033[1m'

NAME=$1

# Intro
echo "$SUR""Welcome to Birds.sh$NOC";
echo "$SUR""       (    (    (      (       (        )  " ;
echo "$SUR""   (   )\ ) )\ ) )\ )   )\ )    )\ )  ( /(  " ;
echo "$SUR"" ( )\ (()/((()/((()/(  (()/(   (()/(  )\()) " ;
echo "$SUR"" )((_) /(_))/(_))/(_))  /(_))   /(_))((_)\  " ;
echo "$SUR""((_)_ (_)) (_)) (_))_  (_))    (_))   _((_) " ;
echo "$SUR"" | _ )|_ _|| _ \ |   \ / __|   / __| | || | " ;
echo "$SUR"" | _ \ | | |   / | |) |\__ \ _ \__ \ | __ | " ;
echo "$SUR"" |___/|___||_|_\ |___/ |___/(_)|___/ |_||_| $NOC" ;
echo "" ;
echo "Creating Project $RED $NAME $NOC" ;
until [[ ${confirm} =~ ^[0-1]+$ ]]; do
    echo "Please confirme this name of project (0 = NO or 1 = YES)";
    read confirm[$1]
done

if [[ ("$confirm" == "0")]] ; then
    while [ -z ${newname[$1]} ]; do
        echo "Please enter the new name or exit (-q)";
        read newname[$1]
        if [[ ("$newname" == "-q" && $# == 1) ]] ; then
            echo "$RED""Exit Project$NOC";
            exit ;
        else
            NAME="$newname"
            echo "Creating Project $RED $NAME $NOC" ;
        fi ;
    done
fi ;

# Path
echo "$GREEN""Please enter the path for install$NOC";
read -p "/" -e path[$1]
cd $path

# Name ok, verify if directory exist
if [ -e "$NAME" ] ; then
    echo "$RED""Warning, the directory exist !$NOC" ;
    echo "Please change this name or delete directory" ;
    exit ;
else
    mkdir $NAME ;
    echo "$GREEN""Creating Successful !$NOC" ;
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
        touch Makefile   ;
        echo "Makefile created" ;
    else
        echo "$GRENN""Directory Create, Good luck for your project !$NOC"
    fi ;
done ;

# Want author ?
while [ -z ${autor[$1]} ]; do
    echo "You want the autor file ? (n = No, else give your login)";
    read autor[$1]
    if [[ ("$autor" == "N" || "$autor" == "n") && $# == 1 ]] ; then
        echo "$RED""No autor file$NOC" ;
    else
        echo "Create autor file ....." ;
        echo "$1" > $NAME/auteur ;
        echo "$GREEN""autor file created !$NOC" ;
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
        echo "*.DS_Store" >> $NAME/.gitignore ;
        echo "a.out" >> $NAME/.gitignore ;
        echo "*.swp" >> $NAME/.gitignore ;
        echo "*.DS_Store, a.out, *.swp add int the .gitignore"
        until [[ ${addgitignore} =~ ^[0]+$ ]]; do
            echo "You want add other name in .gitignore ? (0 for quit)";
            read addgitignore[$1]
            if [[ "$addgitignore" != "0" ]] ; then
                echo $addgitignore >> $NAME/.gitignore ;
            fi ;
        done ;
    fi ;
done ;

echo "$GREEN""You can start your project... Enjoy !$NOC"
