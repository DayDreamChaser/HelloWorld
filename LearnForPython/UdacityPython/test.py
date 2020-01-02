# PAT 1001 (3n + 1) assumption
def assumption(number):
    #number = int(input())
    step = 0
    while number > 1:
        number = number/2 if number%2==0 else (3*number+1)/2
        step += 1    
    return step

#PAT 1002 Wirte this number    
ping_ying = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']
def seperate_num(number):
    divid = []
    for j in range(len(str(number))):
        divid.append(number%10)
        number = number // 10
    return divid
  
def sum_of_number(n):
    #n = int(input())
    length = len(str(n))

    number = seperate_num(n) 
    sum_one = sum(number)
    divid = seperate_num(sum_one)
    divid.reverse()
    
    count = 0
    for i in divid:
        print(ping_ying[i], end="")
        count +=1
        if count < len(divid):
            print(" ", end="")
    
sum_of_number(1234567890987654321123456789)   
    