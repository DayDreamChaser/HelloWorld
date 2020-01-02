# -*- coding: utf-8 -*-
#!/usr/bin/env python
import time

# 杨辉三角 生成器
"""def triangles():
    L = [1]
    while True:
        yield L
        L.append(0)
        L = [L[i - 1] + L[i] for i in range(len(L))]
"""
def triangles():
	L = [] # use to record list
	n = 1
	while True:
	    ret = []
	    for i in range(n):
		    if i == 0 or i == (n - 1):
		        ret.append(1)
		    else:
		        ret.append( L[i-1]+ L[i] )
	    L = ret[:]
	    yield ret
	    n = n + 1
        
set_val = input("Please input a num:")
count_a = 0

for i in triangles():
    print(i)
    time.sleep(0.1)
    count_a +=1
    if count_a > int(set_val):
        break

# 生成器和生成器函数可迭代为Iterator  使用next()
# Str、[]、( )、{1，}、{} is Iterable  两种类型皆可for迭代
from collections.abc import Iterable, Iterator 

if isinstance('sse', Iterable):
    print(True)
if isinstance((), Iterable):
    print(True)
if isinstance({}, Iterable):
    print(True)
if isinstance({1:'1'}, Iterable):
    print(True)
if isinstance({1,}, Iterable):
    print(True)
    
if isinstance((x for x in range(10)), Iterator):
    print(True)
    
# Python for循环本质就是
# 通过不断调用next()函数实现的
for x in [1, 2, 3, 4, 5]:
    pass
# it is equivlent to 

# 首先获得Iterator对象:
it = iter([1, 2, 3, 4, 5])
# 循环:
while True:
    try:
        # 获得下一个值:
        x = next(it)
    except StopIteration:
        # 遇到StopIteration就退出循环
        break
        
def g():
    yield 1
    yield 2
    yield 3

print('Iterable? [1, 2, 3]:', isinstance([1, 2, 3], Iterable))
print('Iterable? \'abc\':', isinstance('abc', Iterable))
print('Iterable? 123:', isinstance(123, Iterable))
print('Iterable? g():', isinstance(g(), Iterable))

print('Iterator? [1, 2, 3]:', isinstance([1, 2, 3], Iterator))
print('Iterator? iter([1, 2, 3]):', isinstance(iter([1, 2, 3]), Iterator))
print('Iterator? \'abc\':', isinstance('abc', Iterator))
print('Iterator? 123:', isinstance(123, Iterator))
print('Iterator? g():', isinstance(g(), Iterator))

# iter list:
print('for x in [1, 2, 3, 4, 5]:')
for x in [1, 2, 3, 4, 5]:
    print(x)

print('for x in iter([1, 2, 3, 4, 5]):')
for i in iter([ i for i in range(6)]):
	print( i, end=" ")

#Python的Iterator对象表示数据流，Iterator可被next()函数调用并不断返回下一个数据
print('next():')
it = iter([1, 2, 3, 4, 5])
print(next(it))
print(next(it))
print(next(it))
print(next(it))
print(next(it))

d = {'a': 1, 'b': 2, 'c': 3}

# iter each key:
print('iter key:', d)
for k in d.keys():
    print('key:', k)

# iter each value:
print('iter value:', d)
for v in d.values():
    print('value:', v)

# iter both key and value:
print('iter item:', d)
for k, v in d.items():
    print('item:', k, v)

# iter list with index:
print('iter enumerate([\'A\', \'B\', \'C\']')
for i, value in enumerate(['A', 'B', 'C']):
    print(i, value)

# iter complex list:
print('iter [(1, 1), (2, 4), (3, 9)]:')
for x, y in [(1, 1), (2, 4), (3, 9)]:
    print(x, y)
