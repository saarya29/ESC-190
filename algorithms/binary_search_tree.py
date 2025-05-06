#mostly all going to be in Python. 

#this is basically a dictionary that's very fast. it usees the 
# set ADT. .
# it can insert into the set, delete things in the set, and Find 
# things in the set. 

class Myset: 
    def __init__(self):
        self.data = []
    def insert(self, x):
        if x not in self.data:
            self.data.append(x)
    def is_in(self, x):
        return x in self.data
    
#insertion and deletion and search are all going to be in O(n)
#because you're going to have to go through all the elements 
#that are in the list. 

#dictionary and maps are basically like sets. 
class MyDict: 
    def __init__(self):
        self.data = []
    def insert(self, x, value):
        if x not in self.data:
            self.data.append(x, value)
    def is_in(self, x):
        for k, value in self.data:
            if k == x:
                return True
            return False
    def get(self, x):
        for k, val in self.data:
            if k == x:
                return val
        return None
    
    #you want to look through the entire tuple ot see if any 
    #of the keys match. 

    #easy to do if what you want is just O(n). harder if soemthing more. 

    #and then you use a binary search tree.

    #you're going to have a parent and its children
    #the children have children and so on. 

    #all the discendants on the left side is smaller than the 
    #root and everything on the right is going to be bigger than the root. 

    #if you want to find where something is, you have to check
    #where you want to go based off where you are starting. 

    #for these types of functions, your funciton complexity 
    #is going to be O(n) = O(log n) steps. 
    #it's as many steps as the height of the tress. if the 
    #tree is complete, then you have 2^h - 1 elements and a 
    #height of h. 
            # this means that h = log(n)
    #complete means a tree has 2 children (each branch i think)

#h is the number of steps needed in the worst case to find the 
#node in the tree. 
# so search in a Binary Search Tree that's complete is o(log(n))

#how to make a tree (it's different frm a graph because you're only going to have 2 children wherea
# s in a graph, there are more things going on)

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

        def make_tree():
            root = Node(3)
            root.left = Node(1)
            root.right = Node(5)
            root.left.left = Node(0)
            root.left.right = Node(2)
            return root
        #     3
        #    / \
        #   1   5
        #  / \   \
        # 0   2 
        #and you basically follow that algorithm and keep on going. 

        def in_tree(root, elem):
            if root is None: 
                return False #nothing exists I think?
            if root.val == elem:
                return True
            if root.val < elem: #i think you're storing each of the values in teh tree called root into the val place (it's like a struct and how that works).
                return in_tree(root.right, elem)
            else: 
                return is_tree(root.left, elem)
            

        def get_val(key, root):
            if root == None: 
                return None
            if key == root.val[0]:
                return root.val[1]
            if key < root.val[0]:
                return get_val(key, root.left)
            else: 
                return get_val(key, root.right)
            
        #what we've seen in here is how to implement a dictionary with O(lon n) retrievall.
        #this is assuming we can make a balanced binary search tree* 
        #using the keys. 

        

