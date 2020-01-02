# -*- coding:UTF-8 -*-

# 不可变类型
T = ( 0, 'Ni', 1, 2, 3)
T = T + tuple("spam")
for x in T:
    print(x)
    
T = [ x*2 for x in T ]
T = [ x  for x in ['b', 'c', 'a', 'd']]
T = tuple(T)
tmp = list(T).sort()
print(tmp)
# tuple 仅有两个的操作
if "aa" in T:
    print( T.index("aa") )
print( T.count('bb') )

# 元组不可变性只支持顶层
T = ( 2, 3, [4, 5], 6 )

# 文件
myfile = open('myfile.txt', 'w')
myfile.write("python file text,\n")
myfile.write("end of text file.\n")
myfile.close()
# 迭代操作
myfile = open('myfile.txt', 'r')
S = myfile.read()
print(S)
myfile.close()

for line in open('myfile.txt'):
    print(line, end='')
myfile.close()    
  
# 文件存储和解析Python object
X, Y, Z = 11, 23, 45
S = 'Spam'
D = {'a':5, 'c':7}
L = [ i for i in range(5)]
F = open("dataFile.txt", 'w')
F.write( S + '\n' )
F.write( "%s,%s,%s\n" % (X, Y, Z) )
F.write(str(L) + '$'+ str(D) + '\n') # 对象转化为字符串存储，$区分
F.close()

"""
 chars = open("dataFile.txt").read()
 print(chars)
"""
# convert str into  python object
F = open("dataFile.txt")
line = F.readline()
print( line.rstrip() )

line = F.readline()
numbers = [ int(x) for x in line ]
print(numbers)

# convert list and dict
line = F.readline()
parts = line.split("$") # eval(): convert str into object
print( [eval(P) for P in parts] ) 
F.close()

# pickle存储Python原生对象
import pickle
F = open("dataFile.pkl", 'wb')
D = {'a': 1, 'e': 4, 'b': 2, 'c': 3}
pickle.dump( D, F) # 对象序列化
F.close()
F =  open("dataFile.pkl", 'rb')
E = pickle.load(F)
print(E)

# BOOL True Flase 数字0为Flase,其他都为真 空对象都为假
if bool(1) != bool([]):
    print( bool('spam') )
if type(1) != type([]):
    print( isinstance([1], list) )
# 避免循环引用 L = ["refer"] L.append(L) 

# print(value, ..., sep=' ', end='\n', file=sys.stdout, flush=False)
a, b, c , *d= [1, 2, 3, 4, 5, 6]
print(a, b, c, sep=" | ", end ="!n" )
log = open("textFile.txt", "w") 
print( a, b, c, d, sep="***", end="\n", file = log)
log.close()
# print函数默认将对象传入到stdout中，显示
import sys
sys.stdout.write("Hello\n")
 