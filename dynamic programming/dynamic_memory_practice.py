# //you're going to visit a node and then figure out where you can get next 
# //keep adding nodes that are neighbours. 
# //from the queue you're going to get the smallest way... using dijkstra's algo. 

# //not going to be on the tset, but guarantees getting you the shortest path. 

houses = [[7, 6, 7, 8, 9, 20],
          [3, 8, 9, 22, 12, 8],
          [16, 10, 4, 2, 5, 7]]

#you need to provide the cost of getting to a certain house.. you look at 
#everything before it instead of everything after it. 

n = 6

cost = [[0] * N,
        [0] * N,
        [0] * N]

cost[0][0] = houses[0][0]
cost[1][0] = houses[1][0]
cost[2][0] = houses[2][0]

for i in range(1, N): #you usually need a for loop.
    cost[0][i] = houses[0][i] + min(cost[1][i - 1],cost[2][i - 1]) #you want to look at everything before as wlel. 
    # the 0 represents the colour red. the minimum is saying that if you're going to colour the ith house in that colour, 
    #then knowing that you can't have your houses painted in the same colour, 
    # you check whether painting the house before was green or blue because that
    #was likely the one that was chosen, and then that colour was chosen because of the one before that.
    #and it's kind of like a linked list moment iykwim. 

    cost[1][i] = houses[1][i] + min(cost[0][i - 1], cost[2][i-1])
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[2][i-1])
    
    #you want to know how many houses there are and you want to know what colour
    #you want the ith house. 

min(cost[0][5], cost[1][5], cost[2][5]) #the n - 1 so that you can determine what the cost might be of th enext one. 

cols = [0] * n

i = n - 1
if cost[0][n-1] <= min(cost[1][n-1], cost[2][n-1]): #the red house was the least costly one. 
    cols[n-1] = 0 #this is kind of like fibonnaci because you're looking back to 
    #see what you have and what you do not have. 

elif cost[1][n-1] <= min(cost[0][n-1], cost[2][n-1]):
    cost[n-1] = 1
else:
    cost[n-1] = 2

#1. You need to find the cost of printing a particular house 

def paint_house_cost(houses, col, i):
    if i == 0: #it's the first house and of your colour. 
        return col[i]
    
    #now suppose you're lookina the 2nd house (or atleast not the first house)
    for costs in houses: #houses is a list of lists. 
        cur_min = sum(sum(costs))
        cur_min_col = -1
        for color in [0,1,2]: #it's looking through a list rather than always iterating through because that's going to be repetitite. 

            if color == col:
                continue
        color_cost_i = paint_house_cost(houses, col, i - 1) #recursive! Personally, I think a recusrive solution for meoisation is better. 
        if color_cost_i < cur_min:
            cur_min = color_cost_i
            cur_min_col = color
        return houses[col][i] + cur_min
    #the current min so what the cost is going to be for that house and I blieve everything else after?






#SECOND EXAMPLE OF THE COINS... YOU CAN ALSO FIND THE TOTAL PATH TOGETHER. 
def opt(t, denomination): #you're trying to find the minimum number of coins to form something. 
    #t is the target. 
    if t < 0:
        return float('inf'), []
    if t == 0:
        return 0, [] #a recursive function
    if t in denomination:
        return 1, [t] #does this make sense?
    #think this all through logically you know all this. 
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

#similar pattern with the recursion... you look at what's before (t - d) and then you also need to compute teh minimum, 
## do ask about this: instead of doing the sum(sum(cost), could you not have 
#just said infinity??? 

def steps(cost):
    n = len(cost)

    opt = [0]* n

    opt[0] = cost[0]
    opt[1] = opt[0] + cost[1]
    opt[2] = min(opt[1] + cost[2], opt[0] + cost[2])

    #now let's work backwards through the staircase to get the least cost plan. 
    #we know the amount to get to eac of the steps. 
    steps[1] = 1
    if opt[2] == opt[1] + cost[2]:
        steps[2] = 1
    else:
        steps[2] = 2
    for i in range(3, n+1):
        options = [opt[i - 1] + cost[i], opt[i - 2] + cost[i], opt[i-3] + cost[i]]
        opt[i] = min(options)
        steps[i] = options.index(opt[i]) + 1 #the 1 is because the stairs start from 1, 2,3 
        #not 0, 1, 2
        #steps is going to store the amount of steps. 
        #the full path is the second part afterwards. 

    #work our way through the staircase to get the least cost plan. 
    solution = []
    i = n-1
    while i > 0:
        solution = [steps[i]] + solution 
        #you're adding to the start of the list because that's the most recent 
        #number of steps you took. 
        i -= steps[i] #the amount of steps you took to get there. 

    return solution
