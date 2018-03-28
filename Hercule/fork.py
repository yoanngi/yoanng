#!/bin/env python
#coding: utf-8

# Sources
#https://pymotw.com/2/multiprocessing/basics.html

import os
import time

#import procname
#procname.setprocname('Canasson 1')

import multiprocessing

def worker():
	"""worker function"""
	print 'Worker'
	return

if __name__ == '__main__':
	jobs = []
	for i in range(4):
		p = multiprocessing.Process(target=worker)
		jobs.append(p)
		p.start()

#os.fork()
#os.fork()

time.sleep(60)
