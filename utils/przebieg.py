#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import argv

f = open(argv[1], 'r')
mode = None
first = True

while True:
	t = f.readline()
	if len(t) < 1:
		break
	if mode == None:
		if t.find('Training set final results') != -1:
			mode = 1
	elif mode == 1:
		if t.find('End of training set final results') != -1:
			mode = None
		else:
			if t.find('->') != -1:
				if first:
					first = False
				else:
					print('\n')
				print(t, end='')
			if t.find('expected wyjscie') != -1:
				print(t[:-16] + 'oczekiwano')
			if t.find('calculated wyjscie') != -1:
				print(t[:-18] + 'otrzymano')
			if t.find('what did the network think (by layers)') != -1:
				print(t[:-42])
			if t.find('Network blad') != -1:
				print('Globalny błąd sieci: ' + t[15:-1])

f.close()
