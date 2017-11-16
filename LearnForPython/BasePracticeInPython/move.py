import math

def move(x, y, step, angle=0):
    nx = x + step * math.cos(angle)
    ny = y +step * math.sin(angle)
    nd = math.sqrt(nx**2 + ny**2)
    return nx, ny, nd

def quadratic(a, b, c):
    if a == 0:
        print("a is zero!")
        return False
    s = math.sqrt(b**2 - 4*a*c)
    x1 = (-b + s) / (2*a)
    x2 = (-b - s) / (2*a)
    return x1, x2
    
def enroll(name, gender, age=6, city='Taizhou'):
    print('name',name)
    print('gender',gender)
    print('age',age)
    print('city',city)

enroll('Bob', 'M', city="NeiMeng")

def power(x, n=2):
    s = 1
    while n > 0:
        s = s * x
        n = n - 1
    return s        

print(power(2.0))

#可变参数 * calc(1,2,3) calc()
def calc(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum
    
nums = [1, 2, 3] #calc(nums[0], nums[1], nums[2])
#simply way use *nums
print(calc(*nums))

#关键字参数 允许你传入0个或任意个含参数名的参数
def person(name, age, **kw):
    print('name:', name, 'age:', age, 'other:', kw)
    #check argument
    if 'city' in kw:
        pass
#可接受更多的参数
person('Michael', 30)
person('Bob', 35, city='Beijing')
person('Adam', 45, gender='M', job='Engineer')
extra = {'city':'Beijing', 'job':'Enginee'}
# is equal to --> person('Jack', 24, **extra)
person('JackLi', 22, city=extra['city'], job=extra['job'])


#limit the keyword argument name just receive city job    
def person1(name, age, *, city='city2', job):
    print(name, age, city, job)
#特殊分隔符* for 命名关键字
person1('person1',15,city='Beijing',job='ii')
#已有可变参数，命名关键字参数不需*
def person2(name, age, *args, city, job):
    print(name, age, args, city, job)
    
# args is tuple, kw is dict    
def f1(a, b, c=0, *args, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)    
    
f1(2, 3, 4, 6, 'a', 'b', abc = '1')
   