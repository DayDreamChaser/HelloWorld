# -*- coding:UTF-8 -*-

""" Python string basic operation and concept
    1. 空字符串  "" and '' and """ """  转义字符\n \t \' \\   raw_str-> r"\now"  "\\n"
    2. s.find('name') s.rstrip()移除空格 s.replace("me","you") s,split(',')分隔
    3. s.isdigit() s.isspace() s.islower s.endswith('spam') s.upper()
    4. for x in s: print(x)迭代  'spam' in s  [c for c in s]  map( ord ,s )映射
"""
s1 = "your" 
s2 = " name" 
s = s1 + s2  
print( s1 * 2, s1[1] ,s[:] , s[0:] ,s[::-1])

# S.split(c) 使用符号c分割S字符串 
line = "aaa bbb ccc 111" 
cols = line.split(" ") # ['aaa', 'bbb', 'ccc', '111' ]

# rstrip() 移除尾部空白
line = "The dawn before the day!\n"
if line.startswith("The") and line.endswith("day!\n"):
    print( line.rstrip() )

# S.join(iterable) -> str 还原字符串，S字符串作为分隔符插入到各迭代字符串间
strList = list(s)
print(strList)  # ['y', 'o', 'u', 'r', ' ', 'n', 'a', 'm', 'e']
s = "".join(strList) # ""作为分隔符，则连接单个字符
testStr = "spam".join(['egg', 'sausage', 'ham', 'sandwich'])
print(s, testStr)

# string reverse
def rStr(str):
	if str=="":
		return str
	else:
		tmp = ['']
		S = list(str)
		for i in range(len(S)//2):
			tmp[0] = S[i]
			S[i] = S[len(S)-i-1]
			S[len(S)-i-1] = tmp[0]
		print("reversed!")
		return "".join(S)

# 字符串常量不可修改，不可变类型 
title = "SpaM" * 4 
print("lens:", len(s) ) 
title = title.lower()
title = title.replace("m", 'rk ')
print(title)

# 新建字符对象，headline变量指向此对象
headline = "knight" + " glory " + "sword" 
print("Meaning " "of" "programming")

home = "this\' is our new home\n"
# 格式化字符->"%s meets %s" % (s1, s2)  "{0} and {1}".format(s1, s2)
hotspot = "%s have no idea how %s i was." % ( "you", "worried" )
hitbox = "That is %d %s bird!" % ( 1, 'dead' )
# 基于字典键值格式化
response = "%(n)d %(x)s" % {"n":100, "x":"start"} #字符串格式符引用字典键值
print( home , hotspot， hitbox, response)

values = {'name':'David', "age":34}
reply = """
Greetings...
Hello %(name)s!
Your age roughly is %(age)s years old
"""
print( reply % values )

# 格式化方法调用 format
template = "{} {} and {}".format('green', 'red', 'purple' )
textline = "{name} wants to eat {food} \n".format( name="Bob", food="meat")
pi = 3.14159 
# 类似C语言printf 格式输出 [06.2f]前补0 ,6字符宽度.2f浮点数输出小数点后2位 
line = "\n{0:f} {1:.2f} {2:06.2f}\n".format( pi, pi , pi)
print( template, textline, line,'{0:X}, {1:o}, {2:b}'.format(255,255,255) )

test = random.choice( ['apple', 'pear', 'banana', 'orange'] )
test += str(123) # str(object)--> string
for animal in ["dog", "cat", "piglet"]:
    print( "%s is a mammal" % animal )
   
# 字符转换   
alpha = []
c = 'a'  # chr() ord()->trans char into int [ASCII]
for i in range(26):
    alpha.append(  chr( ord(c)+i ) )
print(alpha)

binDigit = '11010011' # equal to int( B, 2 ) 
B = binDigit[:]
I = 0
while B != '':
    I = I * 2 + ( ord(B[0]) - ord('0') )
    B = B[1:]
print( "\'%s\' -> %d" % ( binDigit, I ) )

