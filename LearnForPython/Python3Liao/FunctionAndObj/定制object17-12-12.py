# 定制类
# __str__ 
class Student(object):
    def __init__(self, name):
        self.name = name
    # 定义好__str__()方法，返回一个好看的字符串
    def __str__(self):
        return 'Student object (name: %s)' % self.name
    # __repr__()是为调试服务的, 单独输s
    __repr__ = __str__
print(Student('Michael'))
s = Student('Michael')

# 一个类想被用于for ... in循环, 用__iter__()方法返回一个迭代对象
# Python的for循环就会不断调用该迭代对象的__next__()方法
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration()
        return self.a # 返回下一个值
for n in Fib():
    print(n)
    
# __getitem__ 像list那样按照下标取出元素
class Fib(object):
    def __getitem__(self, n):
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a
f = Fib()
print(f[2])
# __getitem__()传入参数可能是一个int，也可是一个切片对象slice 判断
class Fib(object):
    def __getitem__(self, n):
        if isinstance(n, int): # n是索引
            a, b = 1, 1
            for x in range(n):
                a, b = b, a + b
            return a
        if isinstance(n, slice): # n是切片
            start = n.start
            stop = n.stop
            if start is None:
                start = 0
            a, b = 1, 1
            L = []
            for x in range(stop):
                if x >= start:
                    L.append(a)
                a, b = b, a + b
            return L
f = Fib()
f[0:5]     
# 对应的是__setitem__()方法，把对象视作list或dict来对集合赋值
# 最后，还有一个__delitem__()方法，用于删除某个元素      
        
# __getattr__

# Python还有另一个机制，写一个__getattr__()方法，动态返回一个属性
class Student(object):

    def __init__(self):
        self.name = 'Michael'
    # 只有在没有找到属性的情况下，才调用__getattr__
    def __getattr__(self, attr):
        if attr=='score':
            return 99
        elif attr=='age':
            return lambda: 25
        # default return None, so
        raise AttributeError('\'Student\' object has no attribute \'%s\'' % attr)
# Python解释器会试图调用__getattr__(self, 'score')来尝试获得属性
s = Student()
print(s.name)
print(s.score)
print(s.age())
# 作用就是，可以针对完全动态的情况作调用
#print(s.sex)

# 利用完全动态的__getattr__，我们可以写出一个链式调用：
class Chain(object):

    def __init__(self, path=''):
        self._path = path

    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))

    def __str__(self):
        return self._path
    __repr__ = __str__
    
print(Chain().status.user.timeline.list)

# __call__() 直接在实例本身上调用属性
class Student(object):
    def __init__(self, name):
        self.name = name

    def __call__(self):
        print('My name is %s.' % self.name)
s = Student("Michael")
s()
# 一个变量是对象还是函数,判断对象是否能被调用
callable(Student())
callable(max)
# 过callable()函数，可判断一个对象是否是“可调用”对象。
callable([1, 2, 3])

# Python的class允许定义许多定制方法 special-method-names
# https://docs.python.org/3/reference/datamodel.html#special-method-names





        
        