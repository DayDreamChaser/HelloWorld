CN_mobile = [134,135,136,137,138,139,150,151,152,157,158,159,182,183,184,
187,188,147,178,1705]
CN_union = [130,131,132,155,156,185,186,145,176,1709]
CN_telecom = [133,153,180,181,189,177,1700]

def output(operator,phone_num):
    print("operator :",operator)
    print("We're sending verification code via you phone: " + phone_num)

def check_num():
    phone_num = input("Enter your number:")
    if not len(phone_num)==11:
        print("Invalid length, your number should be 11 digits!")
        check_num()   
        
    #input is char, it's need to be convert to integer
    three_num = int(phone_num[0:3])
    four_num = int(phone_num[0:4])
    # or four_num == CN_mobile[-1]   or four_num == CN_union[-1]  or four_num == CN_telecom[-1]
    if three_num in CN_mobile:
        operator = "China Mobile"
        output(operator, phone_num)
    elif three_num in CN_union:
        operator = "China Union"
        output(operator, phone_num)
    elif three_num in CN_telecom:
        operator = "China Telecom"
        output(operator, phone_num)
    else:
        print("No such a operator")
        check_num()

check_num()