def fibbo(n):
    # create a fibbonaci list  
    a = []
    for i in range(n):
        if i == 0 or i == 1:
            a.append(1)
        elif i >= 2:
            a.append(a[i-1] + a[i-2])
    return a

if __name__ == "__main__":
    n = input("Input a num for fibbo:\n")
    print( fibbo( int(n) ) )