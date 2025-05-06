import LL

#you also 
class Graph: 
    def __init__(self, data, num_nodes = 0): #imo for traversals you usually do need to keep track for how many nodes you have. At elast it is useful to do so. 
        self.data = data
        self.connections = [] #for traversal i need to know what each node is connected to. 
        self.num_nodes = num_nodes


    