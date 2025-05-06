import LL
import ds # i think i needed to create this sometime but i never did. 
# Want: the same kind of functions as we have in Graph
# Want to repreesnt the data using adjacency list

# for each node, keep a list of its neighbours (i.e. nodes connected to it)
# use linked lists in order to store the neighbours


#     1
#   / \
# 2    3

# 1: 2->3  # could also be 3->2
# 2: 1
# 3: 1

# One possible design: a Python list of linkedlists, nodes
#nodes[i] is the linked list that contains the neighbours of i

class Graph2:
    def __init__(self, num_nodes = 0):
        self.nodes = []#[None] * num_nodes
        self.node_names = {}
        self.node_names_rev = {}
        self.num_nodes = num_nodes
        for i in range(self.num_nodes):
            self.nodes.append(LL.LL())
    
    def add_node(self, name):
        self.node_names[name] = len(self.nodes)
        self.node_names_rev[len(self.nodes)] = name
        self.nodes.append(LL.LL())
        self.num_nodes += 1

    def is_edge(self, i, j):
        # self.nodes[i] is the list of the neighours of node i
        return self.nodes[i].is_in(j)

    def is_edge_name(self, name1, name2):
        return self.is_edge(self.node_names[name1], self.node_names[name2])

    def put_edge(self, i, j):
        self.nodes[i].insert(0, j)

    def put_edge_name(self, name1, name2):
        return self.put_edge(self.node_names[name1], self.node_names[name2])
    def remove_edge(self, i, j):
        # look through the neighbours of i, remove j from there
        self.nodes[i].remove(j)



# Idea: store a matrix inside of the graph object
#       access the matrix when querying edges
import numpy as np
class Graph:
    def __init__(self, num_nodes):
        self.adj_matrix = np.zeros((num_nodes, num_nodes))

    def is_edge(self, i, j):
        return self.adj_matrix[i][j] == 1

    def put_edge(self, i, j):
        self.adj_matrix[i][j] = 1

    def remove_edge(self, i, j):
        self.adj_matrix[i][j] = 0

def breadth_first_traversal(g, start_name):
    start_i = g.node_names[start_name]
    visited = [False] * g.num_nodes # [False, False, False, ...]
    DS = ds.Queue()
    DS.add(start_i)
    # keep getting a node for DS, adding all its neighbours to DS, and visiting the node
    while not DS.is_empty():
        cur = DS.get()
        if not visited[cur]:
            print(g.node_names_rev[cur])
            visited[cur] = True
            # Now add all the neighbours (nodes with an edge from cur) to DS
            # to be visited later
            cur = g.nodes[cur].head
            while cur:
                if not visited[cur.data]:
                    DS.add(cur.data)
                cur = cur.next


##everything else will literally stay the same. 


def depth_first_traversal(g, start_name):
    start_i = g.node_names[start_name]
    visited = [False] * g.num_nodes # [False, False, False, ...]
    DS = ds.Stack()
    DS.add(start_i)
    # keep getting a node for DS, adding all its neighbours to DS, and visiting the node
    while not DS.is_empty():
        cur = DS.get()
        if not visited[cur]:
            print(g.node_names_rev[cur])
            visited[cur] = True
            # Now add all the neighbours (nodes with an edge from cur) to DS
            # to be visited later
            cur = g.nodes[cur].head
            while cur:
                if not visited[cur.data]:
                    DS.add(cur.data)
                cur = cur.next




#for depth first traversal, you don't even need a stack. can use recursion. 
#mark something as visited. And whatever was not visited, go to them as well after

#you have to keep track of what you've visited. 


def DFS_rec(g, cur, visited = None): #the visited array that we're going to have to initialize. 
    if visited is None: 
        visited = [False]* g.num_nodes #the g i think acts as a graph or a self. Do double check thought. 
    cur_i = g.node_names_rev[cur]
    cur_neighbours = g.nodes[cur_i].head #you're gonna go through the neighbours of cur and visit then. 
    visited[cur_i] = True #node_names is a list of all our indices. 
    print(cur)
    while cur_neighbours:
        if not visited[g.node_names_rev[cur_neighbours.data]]:
            DFS_rec(g, cur_neighbours.data, visited)

#very similar to the friends example we once had in ESC 180.
#g.num_nodes is the number of nodes in the graph
#cur_i = g.node_names_rev[cur] is the index of the current node in an internal list. 
#and you're trying to find the neighbours of teh other nodes. 








if __name__ == '__main__':
    # g = Graph(4) # Graph.__init__(g, 4)
    # g.put_edge(1, 2) # Graph.put_edge(g, 1, 2)
    # print(g.is_edge(1, 2))



    # setting up a matrix
    # import numpy as np
    # M = np.array((10, 10)) # a 10x10 matrix
    # M = np.zeros((10, 10)) # an all-zero 10x10 matrix
    # M[0][1] # row 0, column 1

    airports = Graph2()
    airports.add_node("YYZ")
    airports.add_node("YVR")
    airports.add_node("JFK")
    
    airports.put_edge_name("YVR", "YYZ")
    airports.put_edge_name("YYZ", "YVR")
    airports.put_edge_name("YYZ", "JFK")
    

    breadth_first_traversal(airports, "YVR")
    #    YYZ
    #  / ^  \
    # v  /    v
    # YVR     JFK