#!/bin/bash

# Projet Hercule Birds
# http://blog.inforeseau.com/2010/11/ecrire-script-bash-interactif-avec-saisie-par-lutilisateur

# Color
NOC='\033[0m'
GREEN='\033[32;05m'
RED='\033[31m'
SUR='\033[1m'

NAME=$1
PATH_AV=$2

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

echo $MY_PATH
# Confirmation
until [[ ${confirm} =~ ^[0-1]+$ ]]; do
    echo "Please confirme : $RED$NAME$NOC in $RED $PATH_AV$NOC";
    echo "[y = 1 / n = 0]"
    read confirm[$1] ;
done


# Si confirmation = 0
if [[ ("${confirm[$1]}" == "0")]] ; then
    while [ -z ${newname[$1]} ]; do
        echo "Please enter the new name or exit (q)";
        read newname[$1]
        if [[ ("$newname" == "q") ]] ; then
            echo "$RED""Exit Project$NOC";
            exit ;
        else
            NAME="$newname"
            echo "New Name $RED $NAME $NOC" ;
        fi ;
    done
    while [ -z ${newpath[$1]} ]; do
        echo "Please enter the new path or exit (q)";
        read newpath[$1]
        if [[ ("$newpath" == "q") ]] ; then
            echo "$RED""Exit Project$NOC";
            exit ;
        else
            PATH_AV=$newpath
            echo "New Path $RED $PATH_AV $NOC" ;
        fi ;
    done
fi ;

echo "" ;
echo "******************************************************" ;
echo "Creating Project $GREEN$NAME$NOC in $GREEN$PATH_AV$NOC" ;
echo "******************************************************" ;
echo "" ;

# Verif Path
if [ -d $PATH_AV ] ; then
    echo "$GREEN""PATH ok$NOC" ;
else
    echo "$RED""ERROR PATH$NOC" ;
    echo "Please retry with valid PATH" ;
    exit ;
fi ;

cd $PATH_AV ;

# Verif Name
if [ -e "$NAME" ] ; then
    echo "$RED""Warning, the directory exist !$NOC" ;
    echo "Please change this name or delete directory" ;
    exit ;
else
    mkdir $NAME ;
    echo "$GREEN""Creating $NAME Successful !$NOC" ;
fi ;

echo "" ;

# What this language ?
while [ -z ${language[$1]} ]; do
    echo "What the language use ?";
    read language[$1]
    if [[ ("$language" == "C" || "$language" == "c") ]] ; then
        cd $NAME ;
        echo "$GREEN""Create directory :$NOC";
        echo "$NAME/srcs";
        mkdir srcs ;
        echo "$NAME/includes";
        mkdir includes ;
        echo "$GREEN""Create Makefile :$NOC";
        touch Makefile ;
        echo "Makefile created" ;
        cd ../ ;
    else
        echo "$GRENN""Directory Create$NOC"
    fi ;
done ;

echo "" ;

# Want author ?
while [ -z ${autor[$1]} ]; do
    echo "You want the autor file ? (n = No, else give your login)";
    read autor[$1]
    if [[ ("$autor" == "N" || "$autor" == "n") ]] ; then
        echo "$RED""No autor file$NOC" ;
    else
        echo "Create autor file ....." ;
        echo "$autor" > $NAME/auteur ;
        echo "$GREEN""autor file created !$NOC" ;
    fi ;
done ;

echo "" ;

# Want gitignore ?
while [ -z ${git[$1]} ]; do
    echo "You want the .gitignore? (n = N0, y = YES)";
    read git[$1]
    if [[ ("$git" == "N" || "$git" == "n" )]] ; then
        echo "$RED""No .gittignore$NOC" ;
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
                echo "$GREEN""$addgitignore added !$NOC";
            fi ;
        done ;
    fi ;
done ;

echo "$GREEN""You can start your project... Enjoy !$NOC"
