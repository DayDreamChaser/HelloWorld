def strStr(mainString, otherString):
    if mainString == '':
        print("the length of {0} is zero".format(mainString))
        return False
    elif otherString == '':
        print("the length of {0} is zero".format(otherString))
        return False
        
    lenMain = len(mainString)
    lenOther = len(otherString)
    #check the whether lenOther is larget than lenMain
    if lenMain < lenOther:
        print("out of scope!")
        return False
    
    for i in range(lenMain):
        #check scope of search charactor i + lenOther
        if i + lenOther > lenMain:
            print("Not find!")
            return False
        elif mainString[i:i+lenOther] == otherString:
            print("Found the first position!")
            return i

inputStr = 'Y'
while inputStr !='N':

    bigString = "What is youth, the impetuous fire,what is maid, ice and desire,my dream, your smile"
    testString = input("Please input the search string:")
    print(strStr(bigString, testString))
    
    print("Do you want try one more time?Just tap into /'Y/' or quit by /'N/'")
    inputStr = input()

    
    
     