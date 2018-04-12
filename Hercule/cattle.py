# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    cattle.py                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/12 10:53:53 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/04/12 15:18:28 by yoginet     ###    #+. /#+    ###.fr      #
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
import threading
from subprocess import PIPE, Popen

NOC="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
WHITE="\033[37m"

################################ Fonctions #################################

class MonThread (threading.Thread):
    def __init__(self, jusqua):
        threading.Thread.__init__(self)
        self.jusqua = jusqua
        self.etat = False

    def run(self):
        self.etat = True
        for i in range(0, self.jusqua):
            if (requete == 'GET'):
                r = requests.get(tar1)
                a = r.status_code
                fichier = open("logs_1.txt", "a")
                fichier.write(str(a))
                fichier.write("\n")
                fichier.close()
            else:
                r = requests.post(tar1)
                a = r.status_code
                fichier = open("logs_1.txt", "a")
                fichier.write(str(a))
                fichier.write("\n")
                fichier.close()
        self.etat = False

class MonThread2 (threading.Thread):
    def __init__(self, jusqua):
        threading.Thread.__init__(self)
        self.jusqua = jusqua
        self.etat = False

    def run(self):
        self.etat = True
        for i in range(0, self.jusqua):
            if (requete == 'GET'):
                r = requests.get(tar2)
                a = r.status_code
                fichier = open("logs_2.txt", "a")
                fichier.write(str(a))
                fichier.write("\n")
                fichier.close()
            else:
                r = requests.post(tar2)
                a = r.status_code
                fichier = open("logs_2.txt", "a")
                fichier.write(str(a))
                fichier.write("\n")
                fichier.close()
        self.etat = False
    
    def ft_logs2(status):
        fichier = open("logs_2.txt", "a")
        fichier.write(status)
        fichier.write("\n")
        fichier.close()

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
    r = requests.Request(requete, target)
    print WHITE,
    print r,
    print NOC,
    return requests.get(target).elapsed.total_seconds()

def	ft_total(to1, to2, req):
	t1 = to1 / req
	t2 = to2 / req
	if (t1 < t2):
		print GREEN,
		print "%.3f" % t1,
		print "			",
		print RED,
		print "%.3f" % t2,
		print NOC
	else:
		print RED,
		print "%.3f" % t1,
		print "			",
		print GREEN,
		print "%.3f" % t2,
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

global tar1
global tar2

tar1 = target1
tar2 = target2

################################## Demande complementaires
i = 0
total1 = 0
total2 = 0
jobs = []
print WHITE
saisi = raw_input("Veuillez saisir le nombres de tests : ")
try:
    int(saisi)
    req = int(saisi)
except:
    print RED + "Vous n'avez pas rentrer un nombre..... exit" + NOC
    sys.exit()

global requete
saisi2 = raw_input("Veuillez saisir le type de requetes : GET = 1 / POST = 2 ")
try:
    sa = int(saisi2)
    if (sa == 1):
        a = "GET"
    elif (sa == 2):
        a = "POST"
    else:
        print RED + "Vous n'avez pas rentrer un nombre valide..... exit" + NOC
        sys.exit()
    requete = a
except:
    print RED + "Vous n'avez pas rentrer un nombre valide..... exit" + NOC
    sys.exit()

################################## Time ('req' requests)
print NOC,
print WHITE,
print "Test 1 -> ",
print req,
print " requests:" + NOC
if (target2 == None):
	print WHITE + target1 + NOC
	while (i != req):
            m1 = MonThread(req)
            m1.start()
	    result1 = time_response(target1)
            total1 = total1 + result1
            print WHITE,
	    print "request = ", i,
            print GREEN,
	    print "%.3f" % result1
	    i = i + 1
        print NOC
	print BLUE + "*****************************************************" + NOC
        print GREEN,
        print "moyenne = ",
        moy = total1 / req
        print "%.3f" % moy
        print NOC
else:
	print WHITE + "                                     " + target1 + "		" + target2 + NOC
	while (i != req):
            m1 = MonThread(req)
            m1.start()
	    result1 = time_response(target1)
            m2 = MonThread2(req)
            m2.start()
	    result2 = time_response(target2)
	    total1 = total1 + result1
	    total2 = total2 + result2
            if (result1 < result2):
	        print GREEN,
		print "%.3f" % result1,
		print "			",
                print RED,
		print "%.3f" % result2
		print NOC,
            else:
		print RED,
                print "%.3f" % result1,
		print "			",
                print GREEN,
		print "%.3f" % result2
		print NOC,
	    i = i + 1
	print BLUE + "*****************************************************" + NOC
	ft_total(total1, total2, req)

####################################### Infos Sup
if (target2 == None):
    print WHITE
    print "Informations supplementaire"
    print ""
    print target1
    commandeinfo = 'ab -n 10 -c 2 ' + target1 + '/' + '| grep Server | grep Software'
    p = subprocess.Popen(commandeinfo, stdout=subprocess.PIPE, shell=True)
    (output, err) = p.communicate()
    print output,
    commandeinfo = 'ab -n 10 -c 2 ' + target1 + '/' + '| grep Port'
    p = subprocess.Popen(commandeinfo, stdout=subprocess.PIPE, shell=True)
    (output, err) = p.communicate()
    print output
    print NOC
else:
    print WHITE
    print "Informations supplementaire"
    print ""
    print target1
    commandeinfo1 = 'ab -n 10 -c 2 ' + target1 + '/' + '| grep Server | grep Software'
    p1 = subprocess.Popen(commandeinfo1, stdout=subprocess.PIPE, shell=True)
    (output, err) = p1.communicate()
    print output,
    commandeinfo2 = 'ab -n 10 -c 2 ' + target1 + '/' + '| grep Port'
    p2 = subprocess.Popen(commandeinfo2, stdout=subprocess.PIPE, shell=True)
    (output, err) = p2.communicate()
    print output
    print target2
    commandeinfo3 = 'ab -n 10 -c 2 ' + target2 + '/' + '| grep Server | grep Software'
    p3 = subprocess.Popen(commandeinfo3, stdout=subprocess.PIPE, shell=True)
    (output, err) = p3.communicate()
    print output,
    commandeinfo4 = 'ab -n 10 -c 2 ' + target2 + '/' + '| grep Port'
    p4 = subprocess.Popen(commandeinfo4, stdout=subprocess.PIPE, shell=True)
    (output, err) = p4.communicate()
    print output
    print NOC
print WHITE + "END test, you can consult log***.txt for status code request"
