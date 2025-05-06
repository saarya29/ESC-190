class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
# Example tree:
#     1
#      \
#       4
#        \
#         5
#          \
#           7
root = Node(1)
root.right = Node(4)
root.right.right = Node(5)
root.right.right.right = Node(7)
def sum_bst(root):
    if root is None:
        return 0
    return root.value + sum_bst(root.left) + sum_bst(root.right)
print(sum_bst(root))  # Output: 17