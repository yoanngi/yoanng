#!/bin/bash

MAIL_ADMIN="yoann.ginet@gmail.com"
SUBJETC="Alerte cron"
CORPS_MESSAGE="Alerte, le fichier /etc/crontab a été mofier le `date`"


if  ! crontab -l | grep "/home/yoginet/roger-skyline/scripts/04.sh" ; then
	crontab -l > /tmp/script04
	echo "0 0 * * * /home/yoginet/roger-skyline/scripts/04.sh" >> /tmp/script04
	crontab /tmp/script04
	rm /tmp/script04
fi

var1="8f111d100ea459f68d333d63a8ef2205  /etc/crontab"
MD5=`md5sum "/etc/crontab"`
if [ "$var1" != "$MD5" ]; then 
	echo $CORPS_MESSAGE | mail -s $SUBJECT -c $MAIL_ADMIN
fi
