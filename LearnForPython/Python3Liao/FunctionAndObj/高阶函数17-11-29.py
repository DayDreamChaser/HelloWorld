# 高阶函数 接收函数作为参数，将函数作用于参数值(C语言也支持)
# 1 map() and reduce()

# map() 接受两个参数，map() 一个是函数，一个是Iterable
# map将传入的函数mapping到序列的每个元素
# 并把结果作为新的Iterator返回
def f1(x):
	return 2*x + x*x
    
r = map(f1, [1, 2, 3, 4, 5])
print(list(r))
# map()作为高阶函数，事实上它把运算规则抽象
list(map(str, [1, 2, 3, 4, 5, 6, 7, 8, 9]))

# reduce把一个函数作用在一个序列[x1, x2, x3, ...]上
# 此函数必须接受两个参数，reduce把结果继续和序列的下一个元素做累积计算
# from left to right,let the sequence to be a single value
# 其效果如下
# reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)

# such as sequence add up
from functools import reduce
def add(x, y):  # or use sum([1, 3, 5, 7, 9])
    return x + y
reduce(add, [1, 3, 5, 7, 9])
# 若是将[1,2,3,4,5]变为数字12345
def trans_num(x, y):
    return x * 10 + y
print(reduce(trans_num, [1, 3, 5, 7, 9]))

# 配合map(),写出把str转换为int的函数
from functools import reduce
dict_n = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def fn(x, y):
    return x * 10 + y
    
def char2num(s):
    return dict_n[s]
reduce(fn, map(char2num, '13579'))

# summary
from functools import reduce

def str2int(s):
    def fn(x, y):
        return x * 10 + y
    def char2num(s):
        dict_n = { chr( i+ ord('0') ):i for i in range(10)}
        return dict_n[s]
    return reduce(fn, map(char2num, s))

# simplization 使用lambda函数进一步简化
from functools import reduce

def char2num(s):
    return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]

def str2int(s):
    return reduce(lambda x, y: x * 10 + y, map(char2num, s))

# Practice 1
def normalize(name): 
    return name.lower().capitalize()
L1 = ['adam', 'LISA', 'barT']
L2 = list( map( normalize, L1 ) )
print(L2)

# Practice 2 乘法
def prod(L):
    return reduce(lambda x, y: x*y, L)
print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))
if prod([3, 5, 7, 9]) == 945:
    print('测试成功!')
else:
    print('测试失败!')

# Practice3 利用map和reduce编写一个str2float函数
# 把字符串'123.456'转换成浮点数123.456
def str2float(s):
    # 找到dot位置
    dot_pos = len(s) - 1 - s.find('.')
    s = s.replace('.', '')
   
    def fn(x, y):
        return x * 10 + y     
    def char2num(s):
        return dict_n[s] #dict_n was already assigned
    
    culmu_num = reduce(fn, map(char2num, s))
    # 通过乘法将小数点加上去
    return culmu_num * (10**(-dot_pos))
    
print('str2float(\'123.456\') =', str2float('123.456'))
if abs(str2float('123.456') - 123.456) < 0.00001:
    print('测试成功!')
else:
    print('测试失败!')

    
    