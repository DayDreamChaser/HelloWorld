# 多重继承
# 主要的类层次仍按照哺乳类和鸟类设计
import tensorflow
class Animal(object):
    pass

# 大类:
class Mammal(Animal):
    pass

class Bird(Animal):
    pass

# 各种动物:
class Parrot(Bird):
    pass
class Ostrich(Bird):
    pass
    
# MixIn, add flyable and runnable
class RunnableMixIn(object):
    def run(self):
        print('Running...')

class FlyableMixIn(object):
    def fly(self):
        print('Flying...')
        
# if need runnable,then inherit
class Bat(Mammal, FlyableMixIn):
    pass
class Dog(Mammal, RunnableMixIn, CarnivorousMixIn):
    pass
# 我们优先考虑通过多重继承来组合多个MixIn的功能
# 而非设计多层次的复杂的继承关系 通常，主线都是单一继承下来的
# 例如Ostrich继承自Bird。但如需“混入”额外功能，用多重继承就可实现

# 比如，编写一个多进程模式的TCP服务，定义如下： 用多进程或多线程模型
class MyTCPServer(TCPServer, ForkingMixIn):
    pass
#编写一个多线程模式的UDP服务，定义如下：
class MyUDPServer(UDPServer, ThreadingMixIn):
    pass
# 如果你打算搞一个更先进的协程模型，可以编写一个CoroutineMixIn：
class MyTCPServer(TCPServer, CoroutineMixIn):
    pass
# 这样一来，我们不需要复杂而庞大的继承链
# 只要选择组合不同的类的功能，就可以快速构造出所需的子
