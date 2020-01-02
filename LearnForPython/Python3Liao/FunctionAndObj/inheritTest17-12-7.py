# 继承 inherit
class Animal(object):
    def __init__(self, name):
        self.name = name
    def run(self):
        print('Animal is running...')
        
class Dog(Animal):
   # 子类的run()覆盖了父类的run()
    def eat(self):
        print('{} Eating meat...'.format(self.name))
    def run(self):
        print('Dog is running...')

class Cat(Animal):
    def run(self):
        print('%s is running...' %self.name)
  
class Tortoise(Animal):
    def run(self):
        print('{} is running slowly...'.format(self.name))  
        
dog1 = Dog('LittleEight')
hellokitty = Cat('hellokitty')
dog1.run()
dog1.eat()
hellokitty.run()

a = list() # a是list类型
b = Animal('b') # b是Animal类型
c = Dog('BigOne')
# 判断一个变量类型 isinstance()
print(isinstance(a, list))
print(isinstance(b, Animal))
print(isinstance(c, Animal))

# 看起来像鸭，走起来像鸭，那它就可被看做duck
class Timer(object):
    def run(self):
        print('Start...')
# 并不要求严格的继承体系,不需知晓子类
def run_twice(animal):
    animal.run()
    animal.run()
# ploystate
run_twice(Animal('not'))
run_twice(dog1)
run_twice(hellokitty)
run_twice(Tortoise('turtle'))
run_twice(Timer())


# 获取对象信息
print(type(None))
print(type(hellokitty))
# 判断一个对象是否是函数 使用types模块中定义的常量
import types
def fn():    
    pass

type(fn)==types.FunctionType
type(abs)==types.BuiltinFunctionType
type(lambda x: x)==types.LambdaType
type((x for x in range(10)))==types.GeneratorType

# 判断class的类型：isinstance()函数。是否是实列
isinstance(a, Animal)
isinstance(hellokitty, Cat)
isinstance(c, Dog) and isinstance(c, Animal)

isinstance('a', str)
isinstance([1, 2, 3], (list, tuple))

# 使用dir() 获得所有属性和方法
dir("ABC")
""" ['__add__', '__class__', '__contains__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__getnewargs__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__iter__', '__le__', '__len__', '__lt__', '__mod__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__rmod__', '__rmul__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', 'capitalize', 'casefold', 'center', 'count', 'encode', 'endswith', 'expandtabs', 'find', 'format', 'format_map', 'index', 'isalnum', 'isalpha', 'isascii', 'isdecimal', 'isdigit', 'isidentifier', 'islower', 'isnumeric', 'isprintable', 'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower', 'lstrip', 'maketrans', 'partition', 'replace', 'rfind', 'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip', 'split', 'splitlines', 'startswith', 'strip', 'swapcase', 'title', 'translate', 'upper', 'zfill']
"""
# 比如__len__方法返回长度
# 类似__xxx__的属性和方法在Python中都是有特殊用途的，
# 在len()函数内部，它自动去调用该对象的__len__()方法
if 'adc'.__len__() == len('adc'):
    print(True)
    
class MyDog(object):
    def __len__(self):
        return 100
dog = MyDog()
len(dog) # 此时调用对象内部__len__()
# 配合getattr()、setattr()以及hasattr()剖析对象属性
# getattr(x, 'y') is equivalent to x.y
class MyObject(object):
    def __init__(self):
        self.x = 9
    def power(self):
        return self.x * self.x
obj = MyObject()
hasattr(obj, 'x') # 有属性'x'吗？
print(obj.x)
hasattr(obj, 'y') # 有属性'y'吗？
setattr(obj, 'y', 19) # 设置一个属性'y'
hasattr(obj, 'y') # 有属性'y'吗？
getattr(obj, 'y') # 获取属性'y'
print(obj.y) # 获取属性'y'
# When a default argument is given, it is returned when the attribute doesn't exist
getattr(obj, 'z', 404)  

# 对象的方法
hasattr(obj, 'power') # 有属性'power'吗？
getattr(obj, 'power') # 获取属性'power'
fn = getattr(obj, 'power') # 获取属性'power'并赋值到变量fn
fn # fn指向obj.power
fn() # 调用fn()与调用obj.power()是一样的

# 只有在不知道对象信息的时候，我们才会去获取对象信息
# 判断字节流，fp对象是否存在read方法
def readImage(fp):
    if hasattr(fp, 'read'):
        return readData(fp)
    return None
    
# 给实例绑定属性的方法是通过实例变量，或者通过self变量
class Student(object):
    def __init__(self, name):
        self.name = name

s = Student('Bob')
s.score = 90

# 类绑定属性 类属性，归Student类所有
class Student(object):
    name = 'Student'
s = Student() # 创建实例s
print(s.name) # 打印name属性，因为实例并没有name属性，所以会继续查找class的name属性
print(Student.name) # 打印类的name属性

"""实例属性属于各个实例所有，互不干扰；
类属性属于类所有，所有实例共享一个属性；
不要对实例属性和类属性使用相同的名字，否则将产生难以发现的错误。
"""
class StudentA(object):
    count = 0
    def __init__(self, name):
        self.name = name
        StudentA.count += 1
# 测试: 17-12-9
if StudentA.count != 0:
    print('测试失败!')
else:
    bart = StudentA('Bart')
    if StudentA.count != 1:
        print('测试失败!')
    else:
        lisa = StudentA('Bart')
        if StudentA.count != 2:
            print('测试失败!')
        else:
            print('Students:', StudentA.count)
            print('测试通过!')