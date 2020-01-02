# -*- coding:UTF-8 -*-
# default factors
def add_end(L=None):
    if L is None:
        L = []
    L.append('END')
    print(L)
#add_end()
#add_end([1,2,3])

#1 可变参数
def calc(*numbers):
    sum = 0
    # treat numbers as a tuple
    for n in numbers:
        sum = sum + n * n
    return sum
   
print(calc(1, 3, 4, 6))
#add * to nums, transform  list/tuple as varible argument
nums = [1, 2, 3]
print(calc(*nums))

#2 关键字参数
#允许你传入0个或任意个含参数名的参数 内部组装为dict
def person( name, age, **kw ):
	print( "name:", name, "age:", age)
	for item in kw:
		print( item, ':', kw[item], end="  ")
#必选参数name和age 关键字参数可不选
person('Leiao', 20)
person('Bob', 35, city='Beijing')
person('Adam', 45, gender='M', job='Engineer')
#简化写法 kw just a copy of extra
extra = {'city': 'Beijing', 'job': 'Engineer'}
person('Jack', 24, **extra)

#3 限制关键字参数的名字,用命名关键字参数    
#  *后面的参数被视为仅有的命名关键字参数
def person2(name, age, *, city, job):
    print(name, age, city, job)
    
person2('Jack', 24, city='Beijing', job='Engineer')
# 函数已有可变参数，后命名关键字参数不需特殊分隔符*
# city='Beijing' default argument
def person3(name, age, *args, city='Beijing', job):
    print(name, age, args, city, job)

#组合参数定义的顺序
#必选(pos)参数、默认参数、可变参数、命名关键字参数和关键字参数
def f1(a, b, c=0, *args, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)
    
f1(1, 2)
f1(1, 2, 3, 'a', 'b')
f1(1, 2, 3, 'a', 'b', x=99)
f2(1, 2, d=99, ext=None)

# 对于任意函数，都可通过类似func(*args, **kw)的
# 形式调用它,无论它的参数是如何定义的
args = (1, 2, 3, 4)
kw = {'d': 99, 'x': '#'}
f1(*args, **kw)

# 函数内部解析
def func(num, *fact, **keys):
	"""
	type: num  int
	type: fact iterate
	type: keys iterate
	ret-type: sum int
	"""
	sum = 0
	print( '\ntype of fact:', type(fact), 'type of keys:', type(keys))
	if num > 0:
		for i in range(num):
			sum += fact[i]
			print( "%s --> sum=%s" % (fact[i], sum) )
		for k in keys:
			print(k, '-->', keys[k])
		return sum

L = [1,2 ,3 ,4, 5]
func( 5, *L, name='lucy', age='22', career ='worker') 
	