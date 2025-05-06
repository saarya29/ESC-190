def steps(cost):
    n = len(cost)

    opt = [0]* n

    opt[0] = cost[0]
    opt[1] = opt[0] + cost[1]
    opt[2] = min(opt[1] + cost[2, opt[0] + cost[2]])

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