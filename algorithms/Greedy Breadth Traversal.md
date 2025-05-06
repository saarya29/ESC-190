Greedy Breadth Traversal is when you want o find an estimate for how
fac/ how much you need to travel to get a certain place. 

What is the distance between where you currently are and where you need to get to. 

A* Algorithm (i think combining the dijkastra and the breadth first traversal)
you're doing dijkastra except when assigning priority, the priority is the distance
from the sourec to the poaint where you are + the h(v), the characteristic function.

the nodes that you want to store first are the ones are the shortest part and the sum
of the h(v) is the smallest as possible. 

shortest path and the estimate of how good the node is to getting to the destination. 

it's usually used in NPC and when they need to get somewhere in video games. 



going to where it makes sense and dijkastra