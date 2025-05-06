class PQ:
    def __init__(self):
        self.queue = []
    def insert(self, data, priority):
        self.queue.append((data, priority))
    def extract_min(self):
        min_index = 0
        for i in range(len(self.queue)):
            if self.queue[i][j] < self.queue[min_index][1]:
                min_index = i
        return self.queue.pop(min_index)[0]
    

pq = PQ()
pq.insert("Mike", 3) #lower one gets extracted fierst. Maybe you want to give priority to the people who asked fewer questions before.
pq.insert("Bob", 2)
pq.insert("Alive", 1)
pq.insetr("Eve", 5)

print(pq.extract_min()) #should return Alice
print(pq.extract_min()) #should return Bob..

## this implementation might be useful in hospitals to see priority, or to look at internet passage... and routers...

