N = 6

houses = [[7, 6, 7, 8, 9, 20], #R, this is the cost of painting the house at index 1 (Red)
          [3, 8, 9, 22, 12, 8], #G: the cost of painting the hosues at index 1 (green)
          [16, 10, 4, 2, 5, 7]] #B: the cost of painting the hosues at index 1 (blue)
##problem: paint all the houses at minimum cost. Such that no two adjacent houses have the same colour. 

cost = [[0] * N,
        [0] * N,
        [0] * N]



cost[0][0] = houses[0][0]
cost[1][0] = houses[1][0]
cost[2][0] = houses[2][0]

for i in range(1, N):
    # the min cost to paint the first i houses, with the i-th being painted red
    cost[0][i] = houses[0][i] + min(cost[1][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted green
    cost[1][i] = houses[1][i] + min(cost[0][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted blue
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[1][i-1])

min(cost[0][5], cost[1][5], cost[2][5])

cols = [0] * N
i = N-1
if cost[0][N-1] <= min(cost[1][N-1], cost[2][N-1]):
    cols[N-1] = 0
elif cost[1][N-1] <= min(cost[0][N-1], cost[2][N-1]):
    cols[N-1] = 1
else:
    cols[N-1] = 2

for i in range(N-2, -1, -1):
    cur_min = 10000
    cur_min_col = -1
    for col in [0, 1, 2]:
        if col == cols[i+1]:
            continue
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            cur_min_col = col
    cols[i] = cur_min_col


def paint_house_cost(houses, col, i): ##houses would be the cost, the colour for teh given i... given that you are going to pain the hosue in one colour, and it's going to go up to all the houses and going to make sure that houes ith house is going to be painted in a certain colour.
    '''Return the cost of painting houses
    0, 1, 2, ,,, i, with the i-th houses painted col
    and the total cost minimized'''
    if i == 0:
        return houses[col][i] #you know that you want to paint the 0th house in a certain colour, and then you need to optimize everything before it... but you don't have anything befoer the 0th house, so then there is nothing and you just return the value itself.
    

    cur_min = sum(sum(costs) for costs in houses)
    cur_min_col = -1
    for color in [0, 1, 2]:
        if color == col:
            continue
        cost_color_i, cur_soln = paint_house_cost(houses, color, i-1) #try every combination until i -1... and then you're going to get everything until the i -1th house. 
        ##for colour 1 what would it cost, for colour 2 what would it cost, so on so forth. 
        ##you now have the optimal cost and I guess how you can get there as well as the solution (what is the list that corresponds to that cost.)
        if cost_color_i < cur_min:
            cur_min = cost_color_i
            cur_min_col = color
            cur_min_soln = cur_soln
    sol[i][col] = cur_min
    return houses[col][i] + cur_min, cur_min_sol + [col] ##I know that the (i -1)st house should be painted cur_min_col if I paint the i-th house col. 

#What shold I paint i and what should I paint i - 1? It's jstu going to be col. 
##the cur_min_sol + [col] is just going to be a list that is going to append to the end and i think it will include the ith house... recursively. 
print(paint)





mincost(t) = 1 + min(mincost(t-d1), mincost(t - d2), mincost(t - d3)...)
##we're definetly going to be spending 1 and then whichever is going to be the minimum is what you use. 

mincost(0) = 0 #no coins/houses?
mincost(1) = 1
mincost(2) = 2 #because 2 one cent coins
mincost(3) = 3
mincost(4) = 1
mincost(5) = 1
mincost(6) = 2
            #or 1 + min(mincost(5), mincost{2}, mincost(1)) ##the mincost 4 corresponds to using the 4 cents i think, and then teh mincost(1) ocrresponds to using 5 coins and then teh mincost(5) = 1 i think
mincost(7) = 3
            1 + min(mincost(6), mincost(3), mincost(2))
##you always consider negative to just cost infinity. 

##might need to relook this a bit. 


def mincost(t, denomination):
     if t < 0:
          return float('inf')
     if t == 0:
          return 0
     if t in denomination:
          return 1
    current_min = float('inf')

    for d in denominations:
        current_min = min(current_min, 1 + mincost(t - d, denominations))
    return current_min

print(mincost(8, [1,4,5,10]))  ##need to revise this code a bit. 




