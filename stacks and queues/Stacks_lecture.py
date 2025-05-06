#Stacks: LIFO : LAST IN FIRST OUT. 
#A collection of elements. 
#operations: push and pop
#push: put an element into the stack
#pop: get teh last element that was put into the stack

#Push 5
#push 10
#push 2
#pop # return 2 (or something as such)
#pop #returns 10
#push 20
# pop #return 20

class Stack: 
    def __init__(self):
        self.data = []

    def push(self, elem):
        self.data.append(elem)

    def pop(self):
        return self.data.pop()
        #ret_val = self.data[-1] #the return value
        #self.data.remove(len(self.data)-1)
        #return ret_val
    
    if __name__=='__main__':
        s = Stack()
        s.push(5)
        s.push(10)
        print(s.pop()) #10
        s.push(15)
        print(s.pop())#15