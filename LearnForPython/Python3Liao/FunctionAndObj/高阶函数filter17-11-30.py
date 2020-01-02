# filter and sorted

# filter()把传入的函数依次作用于每个元素
# 然后根据返回值是True还是False,决定保留还是丢弃该元素
def is_odd(n):
    return n % 2 == 1
    
print(list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10, 15])))

# 已出序列的空字符串
def not_empty(s):
    return s and s.strip()

print(list(filter(not_empty, ['A', '', 'B', None, 'C', '  '])))

# 利用filter做埃氏筛法求素数 
# 从2开始，去除2的倍数，得到新数列，再除去第一个数的倍数
def _int_iter():
    n = 1
    while True:
        n = n + 1
        yield n
 
def  _not_divisible(n):
    return lambda x:x % n > 0
 
def primes():
    it = _int_iter()
    while True:
        n = next(it)
        yield n
        it = filter(_not_divisible(n), it)
        
# 打印1000以内的素数:
for n in primes():
    if n < 1000:
        print(n)
    else:
        break        
        
# 检查回文数字
def is_palindrome(n):
    str_n = str(n)
    return str_n == str_n[::-1]
# 测试:
output = filter(is_palindrome, range(1, 1000))
print('1~1000:', list(output))
if list(filter(is_palindrome, range(1, 200))) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191]:
    print('测试成功!')
else:
    print('测试失败!')
    
# sorted() ->Return a new sorted list from the items in iterable.
def bubble_sort( array ):
    # type: array list (int)
    # retype: array list (int)
    A = array[:]
    length = len(A)
    i = 0
    tmp = A[i]
    while i < length:
        for j in range(length - i- 1):
            if A[i] > A[i+1]:
                tmp = A[i]
                A[i] = A[i+1]
                A[i+1] = tmp
        i = i + 1
    return A

# sorted(iterable, *, key=None, reverse=False)
sorted([36, 5, -12, 9, -21])    
sorted([36, 5, -12, 9, -21], key=abs)  
# 字符串排序 按ASCII大小
sorted(['bob', 'about', 'Zoo', 'Credit'])
sorted(['bob', 'about', 'Zoo', 'Credit'], key=str.lower)
# 反向排序 reverse
sorted(['bob', 'about', 'Zoo', 'Credit'], key=str.lower, reverse=True)
# sorted()也是一个高阶函数
# 用sorted()排序的关键在于实现一个映射函数

# 在list L中，name and grade store at a tuple
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
def by_name(t):
	return t[0]

def by_grade(t):
    return t[1]

L2 = sorted(L, key=by_name)
print(L2)
L3 = sorted(L, key=by_grade, reverse=True)
print(L3)
    