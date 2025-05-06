# -*- coding: utf-8 -*-
"""
Created on Mon Mar 10 19:01:42 2025

@author: ashah
"""


#denominations i think:
    #mincost(t) = 1 + min(mincost(t - d1), mincost(t - d2), mincost(t - d3)....)
'''in the context of denomination refers to 
    #a specific value within a set of possible
    values that can be used to solve a problem.
    Often used in cain change problem where 
    each different coin value is considered a denomination'''

def opt(t, denomination): #you're trying to find the minimum number of coins to form something. 
    #t is the target. 
    if t < 0:
        return float('inf'), []
    if t == 0:
        return 0, [] #a recursive function
    if t in denomination:
        return 1, [t] #does this make sense?
    current_min = float('inf') #need to define this. 
    best_choice = None #... this returns the 2 that I got at first i think
   #actually we don't need a function for current min because we already define it right here. 
    #to get the actual optimal list, need to keep track and create a "best_option". Return a tuple?
    bank = []
    for d in denomination:
        #if t - d>= 0:
            #continue #i'm not sure if i need this 
            
        num_coins, type_coin = opt(t - d, denomination) #can also implement how prof guerzhoy did it. 
        if num_coins + 1 < current_min:
            current_min = num_coins + 1
            best_choice = d
            bank = type_coin + [best_choice]
            
    return current_min, bank
    
##Question 3
def canBeSegmented(s, wordDict): #can implement this recursively... could potentially be better. You don't need the optimization i don't think
    if s == "": #empty string. 
        return True
    ##for word in range(0, len(wordDict)): need to relearn dictionary syntax :(
    for word in wordDict:
        #sizestr = len(wordDict[word]) #not quite sure how the implementation prof gave works. 
        if s.startswith(word):
            #i'm going to get rid of those and then return... my logic is that if the starting itself does not have anything then you just have to return False. 
            new_string = s[len(word):] ##from prof guerzhoy! I think sizeofstr would work here as well. 
            if canBeSegmented(new_string,wordDict):
                return True
            #reasoning behind returning true in the recursive call is because you need to return the result of the recursive call so that the function can continue to backup the chain/
            ##might want to clarify this because I am a little bit confused about the reasoning. 
        #else: 
         #   word +1 #do we need this in python... help. 
    return False #in the case that none of the words in the dictionary match with what you're starting with... automatic False. 

        
    


'''  wordle = []
  #have a for loop that goes into each of the letters and then computes the length of the string. 
  for word in range (0, len(wordDict)): #do you need to iterate in Python? 
      string1 = wordDict[word] #first word in python.
      sizestr = len(wordDict[word])
      #implement something similar to strncmp. 
      if s[:sizestr] == wordDict[word]: #apple == apple.
          #you need to remove those letters... and then append it to the list!
          wordle.append(s[:sizestr])
          ''' #another implementation if I wanted to. 
#you're mainly just going to return True or False. 

    
    
if __name__ == "__main__":
    #Question 1b: 
    '''opt[0] = 0
    opt[1] = 1
    opt[2] = 2
    opt[3] = 3
    opt[4] = 1
    opt[5] = 1
    opt[6] = 2 #not sure if I use this?'''
    
    print(opt(8, [1, 4,5]))
    s = "applepenapple" #i'm pretty sure what's in the assignment is a typo... 
    wordDict = ["apple", "pen"]
    print(canBeSegmented(s, wordDict))
    s = "applepenpple" #i'm pretty sure what's in the assignment is a typo... 
    wordDict = ["apple", "pen"]
    print(canBeSegmented(s, wordDict))
    s = "catandog" #i'm pretty sure what's in the assignment is a typo... 
    wordDict = ["cat", "and", "dog"]
    print(canBeSegmented(s, wordDict))
    s = "hiphiphorray"
    wordDict = ["hip", "horray"]
    print(canBeSegmented(s, wordDict))
    
