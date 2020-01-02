# -*- coding:UTF-8 -*-

# list practice: index out of range error from 0 to len(L)-1
L = []
L = [1, 1.024, 'dsp']
print( len(L), L[0:1], L[0:-1], L[0:] )

# Add element: 1.append 2.insert 3.extend 
L.append('AI') # append object to end 
L.append('CS')

ex = ['python','C++','html']
L.extend(ex)   # extend iterable object, L.extend("1")

L.insert(-1,'ML') # L.insert(index, object) -- insert object before index
L.insert(0,"football")
L.insert(len(l)-1,'real')

# search and find pos
L.index('python')  # return first index of value
L.count('python')  # return number of occurrences of value计数

# Delete elemnt: 1.pop 2.remove 3.del 4.clear

# L.pop([index]) -> item: remove and return item at index (default last)
L.pop() 
print(L.pop(0))

L_new = L.remove('dsp') # remove first occurrence of value移除第一个
print(L_new)

del L[0:2]

L_new.clear() # L.clear() -> None -- remove all items from L
print(L_new)

L = [x for x in (-1, 2, -2, 23, 3)]
print(L)

# 原处修改 L.sort() L.reverse()--> no return
# L.sort(key=None, reverse=False) -> None -- stable sort IN PLACE
L_new.sort() 
print("sort in palce", L_new) 
L_new.sort(reverse=True)
print("reverse sort in place", L_new) 
print( sorted(L_new) )  # 返回一个新的对象

L_new.reverse() #  L.reverse() -- reverse *IN PLACE*
print(L_new)


M = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
# get column 2
col2 = [row[1] for row in M]

title = L # 指向同一个list对象
title = L.copy() # shollow copy
title = M[:]

