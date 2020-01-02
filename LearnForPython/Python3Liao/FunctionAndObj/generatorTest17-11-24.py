# -*- coding: utf-8 -*-
# generator 一边循环一边计算的机制，称为生成器
g = (x*x for x in range(10))
next(g)  # 每次生成一个，减小内存占用
for n in g:
	print(n)
    
def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        print(b)
        a, b = b, a + b
        n = n + 1
    return 'done'
    
 
# 函数有 yield关键字，函数则变为generator    
# 变成generator的函数，在每次调用next()的时候执行
# 遇到yield返回，再次执行时从上次返回的yield处继续执行
def g_fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b   # 每次调用next()的候执行，遇到yield语句返回
        a, b = b, a + b
        n = n + 1
    return 'done'
   
f = g_fib(6)
for n in f:
    print(n) # 不能捕获返回值

#调用时生成generator对象，然后用next返回值     
def odd():
    print('step 1')
    yield 1
    print('step 2')
    yield(3)
    print('step 3')
    yield(5)
    
def test_g( g ):
    # 捕获生成器返回值
	while True:
	    try:
	        x = next(g)
	        print( x, end=" " )
	    except StopIteration as e:
	        print( 'GeneratorEnd in %s' % e.value )
	        break    
o = odd()  
test_g(o)


