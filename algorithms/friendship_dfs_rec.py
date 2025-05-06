# -*- coding: utf-8 -*-
"""
Created on Sat Apr 12 10:11:50 2025

@author: ashah
"""

def friendship(friends, person=None, visited=None):
    if visited is None:
        visited = set()  # use a set to keep track of visited people
        max_chain = 0
        # try starting from each person
        for start in friends.keys():
            max_chain = max(max_chain, friendship(friends, start, set()))
        return max_chain
    
    visited.add(person)
    max_length = 0
    
    for friend in friends.get(person, []):
        if friend not in visited:
            length = friendship(friends, friend, visited)
            max_length = max(max_length, length)
    
    visited.remove(person)  # backtrack so we can reuse this node in other paths
    return 1 + max_length  # count this person


def friendships1(friends):
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

friends = {"Carl Gauss": ["Isaac Newton", "Gottfried Leibniz", "Charles Babbage"],
"Gottfried Leibniz": ["Carl Gauss"],
"Isaac Newton": ["Carl Gauss", "Charles Babbage"],
"Ada Lovelace": ["Charles Babbage", "Michael Faraday"],
"Charles Babbage": ["Isaac Newton", "Carl Gauss", "Ada Lovelace"],
"Michael Faraday": ["Ada Lovelace"] }

print(friendships1(friends))