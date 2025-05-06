
def coin_problem(target, denominations):
    if target < 0:
        return float('inf'), [] #you can't have a negative number of coins. 
    if target == 0:
        return 0, []
    if target in denominations: #like 4cents, then it's usually better to just pay with 4 cents (atleast i hope)
        return 1, [target]
    

    min_coins = float('inf')
    bank = [] #basically how you should pay, and what coins you should use. 
    best_choice = None

    for anything in denominations:
        num_coins, type_coin = coin_problem(target - anything, denominations)
        if num_coins + 1 < min_coins:
            min_coins = num_coins + 1
            best_choice = anything #not completely sure this makes sense or if it's even needed. 
            bank = type_coin + [best_choice]#or should it be type_coin..
    return min_coins, bank


denominations = [1, 4, 5]
target = 8
print(coin_problem(target, denominations))