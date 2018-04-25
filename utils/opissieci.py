#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from sys import argv

f = open(argv[1], 'r')
mode = None
layer = ''
weights = []
neuron = 0

def printweigths():
	global weights, neuron
	if layer != '' and len(weights):
		neuron += 1
		l = '('
		for w in weights:
			l += ' ' + w
		l += ' ) # Neuron ' + layer + str(neuron)
		print(l)
	weights = []

while True:
	t = f.readline()
	if len(t) < 1:
		break
	if mode == None:
		if t.find('Network description after training') != -1:
			mode = 1
	elif mode == 1:
		if t.find('End of network description after training') != -1:
			mode = None
		else:
			if t.find('Layer ') != -1:
				printweigths()
				layer = t[6:t.find(':')]
				weigths = []
				neuron = 0
				if layer != '1.':
					if layer != '2.':
						print()
					print('Warstwa ' + layer + ':')
				else:
					layer = ''
			if layer != '' and t.find('Weights') != -1:
				printweigths()
				weights = t[18:-1].split(' ')[1:-1]
			if t.find('Bias weight') != -1:
				weights.insert(0, t[15:-1])

printweigths()
f.close()
