#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import argv

f = open(argv[1], 'r')
mode = None
epoch = -1
errs = []

while True:
	t = f.readline()
	if len(t) < 1:
		break
	if mode == None:
		if t.find('Epoch') != -1:
			epoch = t[8:-2]
			mode = 1
			errs = []
	elif mode == 1:
		if t.find('Network blad') != -1:
			errs.append(float(t[15:-1]))
		elif t.find('End of epoch') != -1:
			print(epoch, max(errs))
			mode = None

f.close()
