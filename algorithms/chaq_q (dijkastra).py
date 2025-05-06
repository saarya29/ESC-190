import numpy
import heapq
class Node: 
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = numpy.inf
    
    def __lt__(self, other):
        return self.distance_from_start < other.distance_from_start

class Con: 
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

    def dijkastra(start, end):
        #you're going to go from your start
        start.distance_from_start = 0
        pq = [(0, start)]
        while pq: 
            current_distance, current_node = heapq.heappop(pq)
            if current_distance > current_node.distance_from_start:
                continue

            for connection in current_node.connections:
                neighbour = connection.node
                weight = connection.weight
                new_dist = current_node.distance_from_start + weight
                
                if new_dist < neighbour.distance_from_start:
                    neighbour.distance_from_start = new_dist
                    heapq.heappush(pq, (new_dist, neighbour))
        return end.distance_from_start #or return the end if you want
    #the node itself.


    def dijkstra_2(start, end_all):
    #you're going to go from your start
        for node in end_all: 
            node.distance_from_start = 0
            pq = [(0, start)]
        while pq: 
            current_distance, current_node = heapq.heappop(pq)
            if current_distance > current_node.distance_from_start:
                continue

            for connection in current_node.connections:
                neighbour = connection.node
                weight = connection.weight
                new_dist = current_node.distance_from_start + weight
                
                if new_dist < neighbour.distance_from_start:
                    neighbour.distance_from_start = new_dist
                    heapq.heappush(pq, (new_dist, neighbour))
        return [(node.value, node.distance_from_start) for node in end_all] #or return the end if you want
    #the node itself.
