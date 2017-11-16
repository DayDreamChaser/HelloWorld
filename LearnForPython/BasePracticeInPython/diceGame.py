import random

def roll_dice(num = 3, points = None):
    if points is None: 
        points = []
    for j in range(num):
        points.append(random.randrange(1,7))
    return points

def roll_result(score):
    if 11 <= score <= 18:
        return "Big"
    if  3 <= score <= 10:
        return "Small"  
    else:
        return False    

def bet_gamble(current_money):
    bet = input("How much you wanna bet ?-")
    bet_money = int(bet)
    #judge the bet_money 
    if current_money >= bet_money > 0:
        return bet_money
    else:
        print("Please bet the right money!")
        bet_gamble(current_money)    
        
def start_game(current_money, rates = 1):
    print("<<<<< GAME STARTS! >>>>>")    
    choices = ["Big", "Small"]
    guess = input("Big or Small:")
    
    bet_money = bet_gamble(current_money)
    current_money = current_money - bet_money

    if guess in choices: 
        print("<<<<< ROLL THE DICE >>>>>")
        #Save as a list 
        points = roll_dice()
        score = sum(points)
 
        print("The points are", points)  
        if guess == roll_result(score):
            print("You Win!")
            current_money += bet_money *(1 + rates)
            print("You gained {},you have {} now".format(bet_money*rates, current_money))
        else:
            print("You Lose!")
            print("You lost {},you have {} now".format(bet_money, current_money))         
       
        return current_money
    else:
        print("Invalid words\n")
        start_game(current_money)
    
init_money = 1000  
current_money = init_money

while current_money > 0:
    current_money = start_game(current_money)  
print("GAME OVER!")