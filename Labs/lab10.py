from notopenai import NotOpenAI
import json
import re
import LL


# Input the API key obtained for the lab
API_KEY = "XkfNBQEOayyXZ4gI4G7K"
CLIENT = NotOpenAI(api_key=API_KEY)
def get_response(prompt):
    chat_completion = CLIENT.chat.completions.create(messages=[{"role": "user","content": prompt,}],model="gpt-3.5-turbo")
    response_str = chat_completion.choices[0].message.content
    return response_str

#Question 3. should give you 120. 


def extract_code(response):  # Assume this function extracts only the Python code
    match = re.search(r'```python\n(.*?)```', response, re.DOTALL)
    return match.group(1) if match else response  # Return code if found, else full response


def check_result(generated_code, test_case): #it's going to get it from global
    passed = 0
    failed = 0

    for case in test_case:
        x = case["intput"] #is this how dictionary syntax works?
        generated_ans = factorial(x)
        expected_codes = case["expected_output"]
        if generated_ans == expected_codes:
            passed +=1
        else:
            failed += 1
        
    print(passed)
    print(failed)
    return passed, failed


#Question 7: 


# def DFS_rec(g, cur, visited = None):
#     if visited == None:
#         visited = [False] * g.num_nodes
        
#     cur_i = g.node_names[cur]
#     cur_neighbour = g.nodes[cur_i].head
#     visited[cur_i] = True
#     print(cur)
#     while cur_neighbour:
#         if not visited[cur_neighbour.data]:
#             DFS_rec(g, g.node_names_rev[cur_neighbour.data], visited)
#         cur_neighbour = cur_neighbour.next

# class Graph2:

#     def __init__(self, num_nodes = 0):
#         self.nodes = []#[None] * num_nodes
#         self.node_names = {}
#         self.node_names_rev = {}
#         self.num_nodes = num_nodes
#         for i in range(self.num_nodes):
#             self.nodes.append(LL.LL())
    
#     def add_node(self, name):
#         self.node_names[name] = len(self.nodes)
#         self.node_names_rev[len(self.nodes)] = name
#         self.nodes.append(LL.LL())
#         self.num_nodes += 1

#     def is_edge(self, i, j):
#         # self.nodes[i] is the list of the neighours of node i
#         return self.nodes[i].is_in(j)

#     def is_edge_name(self, name1, name2):
#         return self.is_edge(self.node_names[name1], self.node_names[name2])

#     def put_edge(self, i, j):
#         self.nodes[i].insert(0, j)

#     def put_edge_name(self, name1, name2):
#         return self.put_edge(self.node_names[name1], self.node_names[name2])
#     def remove_edge(self, i, j):
#         # look through the neighbours of i, remove j from there
#         self.nodes[i].remove(j)
        
#     def where_airport(g, cur):
#         count = 0
#         cur_i = self.node_names[cur] 
#         for i in range(self.num_nodes):
#             print(self.num_names_rev[i]) #going to print all the airports?
#             if i == cur_i: #from what is in DFR_rec?
#                 return count
#             else: 
#                 count +=1
#         return None #in the case where the airport is not in the list. 

# #def airport_iter(g, cur, airport): do i add this into the previous function or create something of my own. 
    
if __name__=='__main__':
    #print(get_response("What is Engineering Science?"))
    response = (get_response("Write a function that takes factorial in python. Just write the function, dont include any other code"))
    generated_code = exec(response)
    print(factorial(5))
    test_case = [{"intput": 3, "expected_output": 6},{"intput": 4, "expected_output": 24}]
    print(check_result(generated_code, test_case))

    '''g = Graph2()

    # Add nodes
    g.add_node("YYZ")
    g.add_node("AMD")
    g.add_node("ORD")
    g.add_node("ATL")
    g.add_node("YVR")
    g.add_node("ATL")
    g.add_node("ORD")
    g.add_node("ATL")


    # Add edges (JFK -> LAX, LAX -> ORD, ORD -> ATL)
    g.put_edge_name("JFK", "AMD")
    g.put_edge_name("AMD", "ORD")
    g.put_edge_name("ORD", "ATL")
    g.put_edge_name("ORD", "ATL")
    g.put_edge_name("ORD", "YVR")

    # Call DFS_rec starting from "JFK"
    DFS_rec(g, "YVR")
        
    position = print(g.where_airport("LAX"))'''