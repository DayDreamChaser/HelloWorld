# -*- coding: utf-8 -*-
class worker:
	def __init__( self, name, pay):
		self.name = name
		self.pay = pay
	def lastName( self ):
		return self.name.split()[-1]
	def giveRaise( self, percent ):
		self.pay *= (1.0 + percent)

class MyQueue(object):
	__queue = [] # pretent private property
	def __init__(self):
		self.__size = len(self.__queue)
	def dequeue(self):
		if self.__size != len(self.__queue):
			self.__size = len(self.__queue)
		if self.__size > 0:
			value = self.__queue.pop(0)
			self.__size -= 1
			return value
		else:
			print("Can't execute! Empty queue!")
	def enqueue(self, item):
		self.__queue.append(item)
		self.__size += 1
	def show(self):
		print(self.__queue)
	def size(self):
		return self.__size
		
class MyStack:
    stack = []
    def  __init__( self ):
        self.size = 0
    def push( self, num ):
        self.stack.append(num)
        self.size += 1
    def pop( self ):
        if self.size >= 1:
            return self.stack.pop()
        else:
            print("Empty stack!!!")
            return None
    def top( self ):
        if self.size >= 1:
            return self.stack[-1]
        else:
            print("Empty stack!!!")
            
class FirstClass:
    def setdata(self, value):
        self.data = value
    def display(self):
        print(self.data)
# 类和实例只是命名空间对象       
x = FirstClass()
x.setdata("KeyError")
x.display()
x.data = "New value"

# from modulename import FirstClass        
class SecondClass(FirstClass):
    def display(self):
        print('Current value = %s' % self.data)
        
z = SecondClass()
z.setdata(42)
z.display()
x.display()

class ThirdClass(SecondClass):
    # 截获运算符，进行重载
    def __init__(self, value):
        self.data = value
    def __add__(self, other):         # On "self + other"
        return ThirdClass(self.data + other)
    def __str__(self):               # On "print(self)", "str()" 
        return '[ThirdClass: %s]' % self.data
    def mul(self, other):
        self.data *= other

a = ThirdClass('abc')
a.display()
print(a)      # trigger __str__
b = a + "efg"   
b.display()
print(b) 
a.mul(4) 
print(a)

#__dict__属性是针对大多数基于类的对象的命名空间字典        
class res:pass        
res.name = "Joy"
res.age = 401      
x = res()
x.name = "Lucy"
print(res.name, x.name)
res.__dict__.keys()  
print(x.__class__)# x.__class__ 实例的类 res.__bases__ 超类        
        