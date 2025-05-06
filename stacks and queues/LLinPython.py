class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# 0->1->2->3->4->5->6
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


    def remove(self, val):
        if self.head.data == val:
            self.head = self.head.next
        else:
            cur = self.head
            while cur.next and cur.next.data != val:
                cur = cur.next
                ##we found that cur.next is the node that you want to remove. We're going to skip over it. 
        if cur.next:
            cur.next = cur.next.next

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

                


#</code>
<code>import LL
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
    def __init__(self, num_nodes = 0): #initially the number of nodes is going to be 0. 
        self.nodes = []#[None] * num_nodes
        self.node_names = {} #a dictionary. 
        self.num_nodes = num_nodes
        self.node_names_rev = {}
        for i in range(self.num_nodes):
            self.nodes.append(LL.LL()) #you're basically choosing to use a linked list. In linked lists, you can always
            #insert somehwere (esp in the beginning, because you can just replace the head with the new node). 


    def add_nodes(self, name):
        self.node_names[name] = len(self.nodes)
        self.nodes.append(LL.LL())
        self.num_nodes += 1 #so now every time you're going to add a node, you're going to add a name to it in the process. 
        self.node_names_rev[len(self.nodes)] = name
    #you can correspond the names to the numbers and vise versa. 
    
    def is_edge(self, i, j):
        # self.nodes[i] is the list of the neighours of node i
        return self.nodes[i].is_in(j)
    
    def is_edge_name(self, name1, name2):
        return self.is_edge(self.node_names[name1], self.node_names[name2])
    #what makes it different from is_edge itself is you need the indices I think in order to access the anmes and vise versae. 
    
    def put_edge_name(self, name1, name2):
        return self.put_edge(self.node_names[name1], self.node_names[name2])

    def put_edge(self, i, j):
        self.nodes[i].insert(0, j)

    def remove_edge(self, i, j):
        #need to look at the neighbours of i, remove j from there. 
        # afterwards look at the neighbours of j, point it towards j +1 i think from there.
        self.nodes[i].remove(j) 
        #we can also name the nodes. One way to do this is by putting numbers to the nodes and then havnig a dictionary with all the names




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


if __name__ == '__main__':
   # g = Graph(4) # Graph.__init__(g, 4)
   # g.put_edge(1, 2) # Graph.put_edge(g, 1, 2)
   # print(g.is_edge(1, 2))


   airports = Graph2()
   airports.add_nodes("YYZ")
   airports.add_nodes("YVR")
   airports.add_nodes("JFK")

   airports.put_edge_name("YVR","YYZ")
   airports.put_edge_name("YYZ","YVR")
   airports.put_edge_name("YYZ","JFK")



   #yyz         
   #/   ^  \  
   #v  /    v
   #yvr     jfk  
#you're going back 


    # setting up a matrix
    import numpy as np
    M = np.array((10, 10)) # a 10x10 matrix
    M = np.zeros((10, 10)) # an all-zero 10x10 matrix
    M[0][1] # row 0, column 1
   


   '''Graph Traversal: you awnt to start 1 and then you want to visit (so that you can print) each vertex exactly one. 
   While (there are non visited nodes
   Initialize the data structure DS, add a non visited vertex vi to DS. Mark vi as being visited. 
   While (DS is not empty)
   Remove vj from DS
   Mark vj as visited
   Add non-visited vertices adjacent to vj to DS)
   
   

   Breadth First-Traversal.

   When we add 3 to the visited pile, you're going to get what's after them and put them into the queue contents. 
   You don't add things to the queue more than once... And then you see which one is more likely to be visited. 
   Assuming there is a path from the node that you start at, everything will get covered (all the nodes)'''


   def breath_first_traversal(g, start_name):
       visited = [False]
       DS = ds.Queue()
       DS.add(start_i)
       #keep getting a node for DS, adding all its neighbours to DS, and then visiting the nodes. 

       while not DS.is_empty():
           cur = DS.get()
           if not visited[cur]:
               print(g.node_names_rev[cur])
               visited[cur] = True#now add all the neighbours #get something to teh queue and then there is this process. 
               cur = g.nodes[cur].head.next
               while cur:
                   if not_visited[cur.data]:
                       DS.add(cur.data)
                   cur = cur.next

                   #at a node, I'll visit all the nodes from the neighbours, get me one thing from the queue to visit, add the nodes, and then add all it's neighbouts. 
                   #because it's a queue, the first thing that gets added is the first that gets removed. FIF0. 

                   #As you add them, then they are also going to be added, but near the end so they are going to be looked at later. 


                   #if instead of a queue, yu're going to be using a stack, then it will go the other way. 
                   #^ Depth First Traversal. 
                   #LIFO VS. FIFO. 
                   