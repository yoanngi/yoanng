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
    return requests.get(target).elapsed.total_seconds()

def	ft_total(to1, to2, req):
	t1 = to1 / req
	t2 = to2 / req
	if (t1 < t2):
		print GREEN,
		print t1,
		print "			",
		print RED,
		print t2,
		print NOC
	else:
		print RED,
		print t1,
		print "			",
		print GREEN,
		print t2,
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

# Time (1 requests)
print WHITE + "1 request:" + NOC
if (target2 == None):
	print WHITE + target1 + NOC
	result1 = time_response(target1)
	print GREEN + "1 request = ",
	print result1,
	print NOC
else:
	print WHITE + target1 + "		" + target2 + NOC
	result1 = time_response(target1)
	result2 = time_response(target2)
	print GREEN,
	print result1,
	print "			",
	print result2
	print NOC

# Time ('req' requests)
i = 0
total1 = 0
total2 = 0
req = 20
print WHITE,
print req,
print " requests:" + NOC
if (target2 == None):
	print WHITE + target1 + NOC
	while (i != req):
		result1 = time_response(target1)
		print (GREEN + "%d request = ", i),
		print result1,
		print NOC
		i = i + 1
else:
	print WHITE + target1 + "		" + target2 + NOC
	while (i != req):
		result1 = time_response(target1)
		result2 = time_response(target2)
		total1 = total1 + result1
		total2 = total2 + result2
		print GREEN,
		print result1,
		print "			",
		print result2
		print NOC,
		i = i + 1
	print BLUE + "*****************************************************" + NOC
	ft_total(total1, total2, req)

# SSL

# Montee de charge


# Sources:
# https://github.com/locustio/locust/blob/master/locust/web.py
# https://pypi.python.org/pypi/performance/0.3.2
# https://github.com/svanoort/python-client-benchmarks/blob/master/benchmark.py
# https://openclassrooms.com/courses/creez-vos-applications-web-avec-flask/requetes-et-reponses
# Flask et gunicorn
# https://github.com/jeffbski/bench-rest
