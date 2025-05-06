class LL:
    def __init__(self):
        self.head = None

    def insert(self, ind, data):
        new_node = Node(data)
        if self.head == None:
            self.head = new_node
        else:
            if ind == 0:
                head_save = self.head
                self.head = new_node
                self.head.next = head_save
            else:
                cur = self.head
                for i in range(ind-1):
                    cur = cur.next
                # right now, cur is the node after which we want to insert
                # need: cur.next = new_node, new_node.next = cur.next
                cur.next, new_node.next = new_node, cur.next
    def is_in(self, data):
        cur = self.head
        while cur:
            if cur.data == data:
                return True
            cur = cur.next
        return False

    def print(self):
        cur = self.head
        while cur:  # can say != None
            print(cur.data, "-> ", end = "")
            cur = cur.next
        print("None")

    
if __name__ == '__main__':
    myLL = LL()
    myLL.insert(0, 123)
    myLL.insert(0, 125)
    myLL.print()

                



import LL
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
    def __init__(self, num_nodes):
        self.nodes = []#[None] * num_nodes
        for i in range(self.num_nodes):
            self.nodes.append(LL.LL())

    def is_edge(self, i, j):
        # self.nodes[i] is the list of the neighours of node i
        return self.nodes[i].is_in(j)

    def put_edge(self, i, j):
        self.nodes[i].insert(0, j)

    def remove_edge(self, i, j):
        pass



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