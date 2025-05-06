# -*- coding: utf-8 -*-
"""
Created on Wed Mar 26 23:06:49 2025

@author: ashah
"""

#visited nodes:S = {A, C, B, E} #everytime you're visiting, you're adding it to the list. 
#
#d(A) = 0
#d(C) = 1
#you're basically finding the quickeest way from getting to one way to another (or the cheapsest)
#d(B) = 2
#d(E) = 3 
##you're adding them in the order in which is the cheapest path I think, and then whatever is left. 
#d(D) = 6

#what are your next options. 

# d(G) = 8
# d(F) = 10
# d(H) = 14 (you have to add everything to get to that amount since D is not directly beside D. )

'''Dijkstra's Algorithm
Dijkstra(G = (V, E), source)

S = {source} #s is the set of explored nodes
d(source) = 0 #d(v) is ths shortest parth from the source to v.

while S != V
choose v belongs to V\S s.t d(u) + |(u, v)| is minimized (u E S)
Add v to S, set d(v) = d(u) + |(u, v)|

When I visit S for the first time, I am going to look at all the neighbours of B and report how much that is going to cost me. And then you're going to look at and maintain the priority queue with the closest neighbout of S to the top.'



'''