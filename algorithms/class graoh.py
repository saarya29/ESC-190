class Graph:
    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.adj_list = {i: [] for i in range(num_nodes)}

    def add_edge(self, src, dest):
        self.adj_list[src].append(dest)
        self.adj_list[dest].append(src)  # undirected graph

    def dfs_recursive(self, cur, visited):
        if visited[cur]:
            return  # Already visited, skip

        visited[cur] = True  # Mark as visited
        print(cur, end=" ")

        for neighbor in self.adj_list[cur]:
            if not visited[neighbor]:
                self.dfs_recursive(neighbor, visited)

# Driver code
num_nodes = 5
g = Graph(num_nodes)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 4)

# Create a visited list initialized to False
visited = [False] * num_nodes

print("DFS traversal starting from node 0:")
g.dfs_recursive(0, visited)