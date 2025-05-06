class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = BST(4)
        print(a) # prints 4
        '''
        return str(self.value)
    
    def third_largest(node):
        current_max = float('-inf')

        #you need to traverse through the graph... same way as with DfS except you use a queue instead of stack
        # this is a binary search tres, not a traversal. 

        #you know that everything bigger is going to be on the left. 

        #i'm going to append all the values that are on the right of the root (+ root)
        temp = []
        for i in range(node):
            temp.append(node.right[i]) # does this even work? I want to add another right so it goes to the right each time.

        #now that you have your list, I need to find the third maximumm
        organized = sorted(temp, Reverse = True) #retrieve the third element, on the second index. 
        return organized[2]

def third_largest_soln(node): #you want to visit the nodes in reversing order. '
    values = []

    def reverse_inorder(n):
        if n is None or len(values) >= 3:
            return 
        reverse_inorder(n.right) #right = larger value. 
        values.appedn(n.value) #visit the node.
        reverse_inorder(n.left)
    reverse_inorder(node)
    if len(values) >= 3:
        return values[2]
    else: 
        return None
    

def part2third_largest(node):
    stack = []
    current = node
    count = 0

    while stack or current: 
        while current: 
            stack.append(current)
            current = current.right #you want to first track the rights since they are bigger. 
        current = stack.pop
        count += 1
        if count == 3:
            return current.value
        current = current.left
    return None

#Q1: Why do we need to look at the left side? 
    #sommetimes to find the third largest element, it is still possible that the element will be on the left subtree of the right parent (subroot)
    #just because you're looking on the right doesn't mean you're dealing with everything on onnly the right side. 

#in here, we have to do reverse-in-order traversal (right-> node-> left. ) which is a deep first taversal technique so you have to use a stack. 

#this code does not work because in Python, you need to look at the left and right sides. 


#  Intuition Tip
# If you're trying to find:

# k-th smallest/largest → Use in-order/reverse in-order (DFS) + stack or recursion

# Level-based operations → Use queue (BFS)