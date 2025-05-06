# -*- coding: utf-8 -*-
"""
Created on Tue Mar  4 05:44:46 2025

@author: ashah
"""
#I have a feeling I don't need these many functions.


class queue:
    def __init__(self, size):
        self.size = size
        self.array = [None]*size
        self.begin = -1
        self.end = -1
        
#i think there are flaws the way i'm handling this.
    def is_empty(self):
        return self.begin == -1 #the purpose of this statement
    
    def is_full(self):
        return(self.end + 1) % self.size == self.begin
##these serve as verifiers... will tell you true or false which you can use later on in the code. 
    
#we needa way of knowing whether we're at the end of the list or not
    def enqueue(self,item):
        if self.is_full(): #ensure this is False before proceeding.
            return None
        if self.is_empty():
            self.begin = 0
        self.end = (self.end + 1) % self.size
        self.array[self.end] = item
        #in queues, as it's FIFO, (also referring to the lab)
        #your first out means you start from the front and then when you have your first out, yuo have to take it from the beginning. 
        
        #else:
        #    self.array.append(item) 
        ##this is what was done during lecture but I'm not sure it's making too much sense :(
            
#don't quite understand what the middle items is for??
##why was he able to call it as an array?

    def dequeue(self): #you're not adding thing, your're dealing with the list itself.
        if self.is_empty():
            return None #you don't have anything to get rid of. 
        
    #if len(self.array) >0:
         #   self.array.pop(0) #i can also use my is_empty function... would be slightly redundant. 
        #else: 
         #   return None
        
##when you dequee, you need something that changes the amount because now you can warp around.
        item = self.array[self.begin] #similar to the example given
        self.array[self.begin] = None
        
        if self.begin == self.end: #you have nothing to call your start.begin anymore. 
            self.being = -1
            self.end = -1
        else:
            self.begin = (self.begin + 1) %self.size
        return item
        
    def __str__(self):
        if self.is_empty():
            return "[]"
        
        result = []
        index = self.begin
        while index != self.end:
            result.append(str(self.array[index]))
            index = (index + 1) % self.size
        if self.end != -1:
            result.append(str(self.array[self.end]))
        return "[" + ", ".join(result) + "]"
        #return str(self.array)
        
    ##unlike what I think we did in class, we can't just compare teh two names and therecorresponding values. We're looking at data. 
    ##you need to interate through and then sort. 
##Sorting the queue in lexicographic order
    def __iterate__(self):
        if self.is_empty():
            return ([])
        index = self.begin
        while index != self.end:
            yield self.array[index]
            index = (index + 1) %self.size
        yield self.array[self.end]
##okay so I searched this up but yiel id the best way to 
#iterate over a sequence, and produces these values one
#at a time when necessary. (they are efficient for larger data types)

            
    def __lt__(self, other):
        return self.enqueue <other.enqueue ## this is closest thing that makes sense to me
    
if __name__ == '__main__':
    '''q = queue(3)
    q.enqueue(5)
    q.enqueue(10)
    q.enqueue(15)
    q.enqueue(20)
    q.enqueue(25)
    print(q)
    q.dequeue()#it will delete the first one either way. 
    print(q)
    q.dequeue()
    print(q)'''
    q = queue(3)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    print(q)  # Output: [10, 20, 30]
    q.dequeue()
    print(q)  # Output: [None, 20, 30]
    q.enqueue(40)
    print(q)  # Output: [40, 20, 30] (Wrapped Around)
##i'm a bit confused about how python 
#goes about warping because how will it know the 
#size of the queue and when we enqueue it after a point, will go 
#through the end... like i know we have the length but is there a 
#predetermined length for a queue?

##i'm not quite too sure how to test it, also because I'm not sure I did it correctly. 
