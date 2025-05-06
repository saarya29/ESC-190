#MyList is actually a custom class (so don't write a random fnction that can do this.)

class MyList(list):
    def __init__(self, data):
        super().__init__(data)

    #super(). is important because it gives you access to the parent class list. 
    #and then the __init__ (data) is responsible for initializing the list with the given data. 
    
    def average(self):
        return sum(self) / len(self)
    
    def __lt__(self, other):
        return self.average() < other.average()