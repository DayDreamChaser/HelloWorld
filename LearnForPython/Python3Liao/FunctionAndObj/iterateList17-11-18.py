from collections import Iterable
isinstance('abc', Iterable) # str是否可迭代

isinstance([1,2,3], Iterable) # list是否可迭代

for i, value in enumerate(['A', 'B', 'C']):
    print(i, value)
    
def findMinAndMax( L ):
	if L == [] or type(L) != type([]):
		return None, None
	elif len(L) == 1 :
		return L[0], L[0]
	else:
		min = max= L[0]
		for item in L:
			if item > max:
				max = item
			if item < min:
				min = item
		return min,max

# 测试
if findMinAndMax([]) != (None, None):
    print('测试失败!')
elif findMinAndMax([7]) != (7, 7):
    print('测试失败!')
elif findMinAndMax([7, 1]) != (1, 7):
    print('测试失败!')
elif findMinAndMax([7, 1, 3, 9, 5]) != (1, 9):
    print('测试失败!')
else:
    print('测试成功!') 


#列表生成式子
d = {'x': 'A', 'y': 'B', 'z': 'C' }
a_list = [k + '=' + v for k, v in d.items()]
print(a_list)   

[x * x for x in range(1, 11) if x % 2 == 0]
[m + n for m in 'ABC' for n in 'XYZ']

L = ['Hello', 'World', 'IBM', 'Apple']
print([s.lower() for s in L])

import os # 导入os模块，模块的概念后面讲到
[d for d in os.listdir('.')] # os.listdir可以列出文件和目录

import re
[ f for f in os.listdir('.') if re.search(r'__\w+__', f)]
