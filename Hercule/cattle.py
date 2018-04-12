# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    cattle.py                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/11 09:29:20 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/04/11 15:46:09 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/usr/bin/env python
# coding: utf-8

############################## Import & Color ###############################

import os
import sys
import time
import requests
import subprocess
# import pytest
# python 3 seulement
from subprocess import PIPE, Popen

NOC="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
WHITE="\033[37m"

################################ Fonctions #################################

def usage():
    print ("usage: python cattle.py -1 [TARGET_1]")
    print ("For test target")
    print ("")
    print ("usage: python cattle.py -c [TARGET_1] [TARGET_2]")
    print ("For compare target_1 and target_2")
    sys.exit()

def ping(target):
    toping = Popen(['ping', '-c', '3', target], stdout=PIPE)
    output = toping.communicate()[0]
    hostalive = toping.returncode
    if (hostalive == 0):
        print (GREEN + target + " is up" + NOC)
    else:
        index = target.find('http://')
        if (index == -1):
            print (RED + target + " is down" + NOC)
        else:
            print (RED + target + ": invalide format" + NOC)
        sys.exit()

def asciiart():
    print BLUE + "        ________________________________________ "
    print "        |,---\"-----------------------------\"---,| "
    print "        ||___    ..........................    || "
    print "        ||====\ :HHHHHHHHHHHHHHHHHHHHHHHHHHH   || "
    print "        ||=====):H c> benchmark running#   H   || "
    print "        ||====/ :H                         H   || "
    print "        ||\"\"\"   :H                         H   || "
    print "        ||CATTLE:H                         H   || "
    print "        ||      :HHHHHHHHHHHHHHHHHHHHHHHHHHH   || "
    print "        ||_____,_________________________,_____|| "
    print "        |)_____)-----.| / O S X \ |.-----(_____(| "
    print "      //\"\"\"\"\"\"\"|_____|=----------=|______|\"\"\"\"\"\"\"\ "
    print "     // _| _| _| _| _| _| _| _| _| _| _| _| _| _| \ "
    print "    // ___| _| _| _| _| _| _| _| _| _| _| _|  |  | \ "
    print "   |/ ___| _| _| _| _| _| _| _| _| _| _| _| ______| \ "
    print "   / __| _| _| _| _| _| _| _| _| _| _| _| _| _| ___| \ "
    print "  / _| _| _| _| ________________________| _| _| _| _| \ "
    print " |------\"--------------------------------------\"-------| "
    print " `-----------------------------------------------------' " + NOC

def mise_en_forme(target):
    entete1 = "http://www."
    entete2 = "http://"
    if target == None:
        return
    index = target.find('www')
    if (index == -1):
        retour = entete1 + target
    else:
        retour = entete2 + target
    return retour


def time_response(target):
    if target == None:
        return
    r = requests.Request('GET', target)
    print GREEN + "Response time(1) : ",
    print requests.get(target).elapsed.total_seconds()
    print NOC

################################ Programme #################################

# Check & Verif Arguments
if (len(sys.argv) == 1):
    usage()
    sys.exit()

if (sys.argv[1] == "-1" and len(sys.argv) == 3):
    target1 = sys.argv[2]
    ping(target1)
    target2 = None
elif (sys.argv[1] == "-c" and len(sys.argv) == 4):
    target1 = sys.argv[2]
    ping(target1)
    target2 = sys.argv[3]
    ping(target2)
else:
    usage()

# Start benchmark
asciiart()

# Add "http://"
target1 = mise_en_forme(target1)
target2 = mise_en_forme(target2)

# Time
print WHITE + target1 + NOC
time_response(target1)
if (target2 != None):
    print WHITE + target2 + NOC
    time_response(target2)

# SSL

# Montee de charge


# Sources:
# https://github.com/locustio/locust/blob/master/locust/web.py
# https://pypi.python.org/pypi/performance/0.3.2
# https://github.com/svanoort/python-client-benchmarks/blob/master/benchmark.py
# https://openclassrooms.com/courses/creez-vos-applications-web-avec-flask/requetes-et-reponses
# Flask et gunicorn
# https://github.com/jeffbski/bench-rest
