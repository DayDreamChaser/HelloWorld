# 匿名函数lambda
list(map(lambda x: x * x, [1, 2, 3, 4, 5, 6, 7]))
L = list( filter( lambda x: x%2, range(1,20) ) )
def my_map( func, sequ ):
	return ( func(x) for x in sequ )
    
# 关键字lambda表示匿名函数，冒号前面的x表示函数参数
# lambda x: x * x实际上就是：
def f(x):
    return x * x
    
# 匿名函数有个限制，就是只能有一个表达式
# 不用写return，返回值就是该表达式的结果

# 匿名函数也是一个函数对象
f = lambda x: x * x
print(f(5))

# as the same way,也可以把匿名函数作为返回值返回
def build(x, y):
    return lambda: x * x + y * y
f1 = build(10, 11)
print(f1())

#改造代码
def is_odd(n):
    return n % 2 == 1

L = list(filter(is_odd, range(1, 20)))
# change into:
L1 = list(filter(lambda x: x % 2 == 1, range(1, 20)))
# or
L2 = list(filter(lambda x: x % 2, range(1, 20))) 
print(L1)
print(L2)

import random
def testFunction():
    time = 5
    car_positions = [1, 1, 1]
    while time:
        time -= 1
        print('')
        for i in range( len(car_positions) ):
            if random.random() > 0.3:
                car_positions[i] += 1
    for i in range(len(car_positions)):
        print('-' * car_positions[i])

# Pipeine: mpa/filter替换循环       
def even_filter(nums):
    return filter(lambda x: x%2==0, nums)
 
def multiply_by_three(nums):
    return map(lambda x: x*3, nums)
 
def convert_to_string(nums):
    return map(lambda x: 'The Number: %s' % x,  nums)
 
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
pipeline = convert_to_string(
               multiply_by_three(
                   even_filter(nums)
               )
            )
for num in pipeline:
    print(num)
        