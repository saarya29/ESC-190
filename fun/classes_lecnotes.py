import LL

#NOTE FOR SELF: there are two different implementations in the same code.... the ones that are commecnted are from 
## March 11?/ the other ones are from march 13th and they take things from LL. You can put them into the LL file. 
class graph: 
def __init__(self, num_nodes): #you need the side of teh matrix to make it. 
    ##self.adj_matrix = np.zeros((num_nodes, num_nodes))
    ##instead let's create an "empty list?"
    self.nodes = [None] + num_nodes
    ##we want a separate linked list that we can append to. Python doesn't have a built in linked list. Need ot build it. 
    for i in range(self.num_nodes):
        self.nodes.append(LL.LL()) ##you need to go into teh linked list and then find if it's ther.e 
#edges are the connections between the nodes (RECALL)
#IF YOU HAVE A TWO WAY DIRECTION, YOU PUT IN 1 FOR 7- 8 AND ANOTHER 1 FOR 8-7 TOO. 

'''want to store something like a python lisst like a linked list.
nodes[i] is the linked list that contains the neighbours of i.

Idea is store a matrix inside of the grap hobject, and to access tha matrix when querying edges. 
'''
#recall that self is a graph and i and j are two nodes. 
#we send in the object each time, and then you have to check from there whether we have an i and a j. 
#the idea is to store a matrix inside of the graph object and then access the matrix when querying edges. 
def is_edge(self, i, j):
    ##return self.adj_matrix[i][j] ==1
    if self.is_edge(i, j):   
def is_in(self, data):
    cur = self.head
    while cur: 
        if cur.data == data: 
            return True
        cur = cur.next
        return False
#degree d = the large possible number of neighbours any node could have. 
#Why did we used a linked list when we could have just used a normal list? You might potentially have to move everything
##it depends on how you are trying to work with your data structure. this is good if you want 
def put_edge(self, i, j):
    ##self.adj_matrix[i][j] ==1
    self.nodes[i].insert(0, j)
    #is self.is_edge(i, j):
    #return. 
    #from LL, the insert takes the index and the makes everything = 0. It seems asymmetric because you're using nodes but then you're oging to put j. 
    #this representation that you have a certain amount of nodes and then you also have to look at the neighbours. 
def remove_edge(self, i, j):
    ##self.adj_matrix[i][j] == 0
    self.nodes[i].remove(j) #done!
    ##if user is allowed to call put_edge(1, 2) twice, need to either take care of it inside put_edge or inside remove_edge.
import numpy as np
M = np.array((10,10)) # a 10 by 10 matric. 
M = np.zeros((10,10))
M[0][1] #row 0 and 1 column. 
if __name__ == '__main__':
    g = Graph(4) #graph __init__(g,4)
    g.put_edge(1,2) #graph put edge(g, 1, 2)
    print(g.is_edge(1,2))
#adjacency matris: the matrix is symmetric for undirected groups. 
#another way to have adjacency lists is to treat it like a bunch of linked lists and then working it that way. 
#complexity of operations: operations:
##is there an edge between vi and vj?
#adjaceny matrix: O(1)
##adjacency list: O(d)
#Find all the vertices that are adjacent to vi
#--> adjacent matrix: O(|V|)
# ADJACENCY LIST: O(d)
# Space Requirements: O(|v|^2)
##-> need to store |v|^2 matrix entries. 
#adjency list: need ot store |V| linked lists. Collectively, the linked list 
#contain |E| entries, so the space requirement is a1|V|
# + a2|E|, which is the same as O(|V| + |E|)
##you need to store all the neighbours of the vertices as well i think
#if you look at the slides, 0 has neighbours 2 and 5, so 
#it shows up (kind of looking like a linked list) but it's trying to say that they are both attached in a way to 0.
#arrays are O(d)? 
