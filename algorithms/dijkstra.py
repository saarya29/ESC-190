# -*- coding: utf-8 -*-
"""
Created on Wed Mar 26 23:06:20 2025

@author: ashah
"""

import numpy as np
import heapq #priority queue with 0(log n) push and pop

pq = heapq.heapify([])
heapq.heappush(pq, (1,"Praxis"))
heapq.heappush(pq, (2,"Calculus"))
heapq.heappush(pq, (0,"C!"))
print(heapq.heappop(pq))


a = set([1,4,2,1])
for e in a:
    print(e)

class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight
        
        
yyz = Node("YYZ")
lax = Node("LAX")
yul = Node("YUL")
yyz.connections.append(Con(lax, 1000))
yyz.connections.append(Con(yul, 300))



def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set([start])
    current = start
    to_be_considered = [(0, start)]
    while current != end:
        '''commented code = potential way, but not the best'''        
        # cur_dist = np.inf
        # cur_v = None
        # for node in visited:
        #     for con in node.connections:
        #         if con.node in visited:
        #             continue
        #         if cur_dist > node.distance_from_start + con.weight:
        #             cur_dist = node.distance_from_start + con.weight
        #             cur_v = con.node
        
        cur_dist, current = heapq.heappop(to_be_considered)
        current.distance_from_start = cur_dist
        visited.add(current)
        
        for con in current.connections:
            if con.node in visited:
                continue
            heapq.heappush(to_be_considered, (con.weight + current.distance_from_start, con.node))
        
        
        
    return current.distance_from_start







############################
#Queue: [(1, C), (2,c), (6,D)]
d(A) = 0
d(c) = 1
pop the next thing from the queue
d(b) = 2
d(e) = 3
d(d) = 6
d(g) = 8

#it's the list of the neighbouring nodes and which 
#one gets the higher priority. ? 

//it's like whatever if put in first comes out first. Check out the youtube 
video if need clarification (March 26 2025)'                                          