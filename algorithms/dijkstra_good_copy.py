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
    visited = set()
    to_be_considered = [(0, start)]
    current = start
    while current != end:
        
        cur_dist, current = heapq.heappop(to_be_considered)
        if current in visited:
            continue
        current.distance_from_start = cur_dist
        visited.add(current)
        for con in current.connections:
            if con.node in visited:
                continue
            heapq.heappush(to_be_considered, (con.weight + current.distance_from_start, con.node))

    return current.distance_from_start
                                                                                                                                                                       vvvvvvvvvvvc              
yyz = Node("YYZ")
lax = Node("LAX")
yul = Node("YUL")
yyz.connections.append(Con(lax, 1000))
yyz.connections.append(Con(yul, 300))
lax.connections.append(Con(yul, 500))
print(dijkstra(yyz, yul))