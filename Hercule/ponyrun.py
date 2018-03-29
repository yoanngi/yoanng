#!/bin/env python
#coding: utf-8

# Sources
#https://pymotw.com/2/multiprocessing/basics.html

import os
import time

import multiprocessing

def canasson0():
	"""Xanthos"""
	os.system('ls')
	time.sleep(60)
	return

def canasson1():
	"""lampon"""
	os.system('say "tagada tagada tagada"')
	time.sleep(60)
	return

def canasson2():
	"""dinos"""
	os.system('echo 101 > 101')
	time.sleep(60)
	return

def canasson3():
	"""podargos"""
	os.system('echo 42 > 42')
	time.sleep(60)
	return

if __name__ == '__main__':
	jobs = []
	pa = multiprocessing.Process(target=canasson0)
	pb = multiprocessing.Process(target=canasson1)
	pc = multiprocessing.Process(target=canasson2)
	pd = multiprocessing.Process(target=canasson3)
	jobs.append(pa)
	jobs.append(pb)
	jobs.append(pc)
	jobs.append(pd)
	pa.start()
	pb.start()
	pc.start()
	pd.start()
#	pa.join()
#	pb.join()
#	pc.join()
#	pd.join()
time.sleep(60)
