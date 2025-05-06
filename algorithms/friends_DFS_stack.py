# -*- coding: utf-8 -*-
"""
Created on Sun Apr  6 15:25:29 2025

@author: ashah
"""

#Ideas: using a graph but you use iteration instead of recursion.

def friendships(friends):
    max_chain = 0
    longest_chain = []
    #Iterate through the dictionary
    for start in friends:
        stack = [(start, [start])]
        
        while stack:
            current, path = stack.pop()
            for neighbour in friends.get(current, []):
                if neighbour not in path:
                    new_path = path + [neighbour]
                    stack.append((neighbour, new_path))
                    max_chain = max(max_chain, len(new_path))
                    
                if len(path) > len(longest_chain):
                    longest_chain = path
    return max_chain, longest_chain
    #the pop will remove and return the last item that was added to the stack. 
    #having it there will allow you to explore the 
    #deepest path first
#the reason you use a stack for DFS is becuase a 
#stack will naturally remember the node you are on, the path you have taken
#and where to return to when you finish exploring a brankch. 
# A visualization/ Example of How This Works. 
# friends = {
#     'Alice': ['Bob', 'Charlie'],
#     'Bob': ['David'],
#     'Charlie': [],
#     'David': []
# }
# Initial Stack:
# [('Alice', ['Alice'])]
# Step 1 (pop Alice):
# You get: current = 'Alice', path = ['Alice']
# Alice’s friends: ['Bob', 'Charlie']
# Push onto stack:
# ('Bob', ['Alice', 'Bob'])
# ('Charlie', ['Alice', 'Charlie'])
# Step 2 (pop Charlie):
# Charlie has no friends → nothing to push
# Step 3 (pop Bob):
# Bob's friend: ['David']
# Push ('David', ['Alice', 'Bob', 'David'])
# Step 4 (pop David):
# No friends → done
# Result: Longest chain = ['Alice', 'Bob', 'David'] (length 3)
#whenever you can't have recursion but you need to use
#DFT, you use it as a stack... recall that the only real 
#difference between BFT andDFT is BFT uses queue, 
#while DFT uses a stack.
   
    
friends = {"Carl Gauss": ["Isaac Newton", "Gottfried Leibniz", "Charles Babbage"],
"Gottfried Leibniz": ["Carl Gauss"],
"Isaac Newton": ["Carl Gauss", "Charles Babbage"],
"Ada Lovelace": ["Charles Babbage", "Michael Faraday"],
"Charles Babbage": ["Isaac Newton", "Carl Gauss", "Ada Lovelace"],
"Michael Faraday": ["Ada Lovelace"] }
print(friendships(friends))