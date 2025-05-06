class Node: 
    def __init__(self, data):
        self.data = data
        self.next = None #that's what creates a node... similar to what we do C. 

        ##we don't need to specify our "type" so technically we can have a linked list full of everything whereas in 
        ##C we can only have them with integers or character.s.

## 0->1->2->3->4 etc...

class LL: 
    def __init__(self):
        self.head = None

    def insert(self, index, data):
        ##make the head into the new node. And then find the index and then put it in there.
        new_node = Node(data)
        if self.head == None: 
            self.head = new_node #don't need to do anything else. Otherwise need to go through the linked list to find where we want to add the element. 
        else: 
            if index == 0:
                head_save = self.head
                self.head = new_node
                self.head.next = head_save #could make more elegant if we wanted to. We're making a swap between new node and head... could use teh multiple assignment thing like how we did in ESC 180
            else:
                cur = self.head
                for i in range(index - 1): #so that we can insert before the next one. 
                    cur = cur.next
                ##suppose we wanted to insert at index 2. Right now, cur is the node after which we want to insert.
                # need: cur.next = new_node, new_node.next
                ##REMEMBER: ARROWS AREN'T A THING IN PYTHON. 
                cur.next, new_node.next = new_node, cur.next #the current current next?

    def remove(self, data): #same way the remove function works from before... the remove function. 
        if self.head.data == data: 
            self.head = self.head.next # head is now at next i think. 
            return
        cur = self.head 
        while cur.next != None and cur.next.data != data:
            cur = cur.next
            #Either cur.next is none, or cur.next.data == data... we've already checked is the head of the current one matches (so you aren't skipping anything.)
            if cur.next == None:
                print("Error trying to remove", data)
                return 
            #now you're going to be removing cur_next. 
            cur_next = cur.next.next ##you're basically going to be skipping over the cur_next when this runs by the assignment. 
            
        


def print(self):
    #you need to travese teh list to print it. 
    cur = self.head
    while cur != None:#can also say while != None
        print(cur.data, "->", end = "")
        cur = cur.next
    print("None")



if __name__ == '__main__':
    myLL = LL() #because the init doesn't take anything Recall that you need to provide this type fo syntax for init and self things in class. 
    myLL.insert(0, 123)
    myLL.insert(0, 124)
    myLL.insert(0, 125)
    myLL.print() ##for some reason, classes become similar to C... you need a function to print things properly. 

