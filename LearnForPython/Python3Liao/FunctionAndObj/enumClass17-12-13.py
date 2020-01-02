# 使用枚举类
# 大写变量通过整数来定义常量
JAN = 1
FEB = 2
MAR = 3
# 仍为Int变量

# 枚举类型定义一个class类型，每个常量都是class的一个唯一实例
from enum import Enum

# Month类型的枚举类，可以直接使用Month.Jan来引用一个常量
Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 
             'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))
     
# value属性则是自动赋给成员的int常量，默认从1开始计数。     
for name, member in Month.__members__.items():
    print(name, '=>', member, ',', member.value)
    print(name, '=>', member, ',', member.value)

# 如果需要更精确地控制枚举类型，可以从Enum派生出自定义类：
from enum import Enum, unique
# @unique装饰器可以帮助我们检查保证没有重复值
@unique
class Weekday(Enum):
    Sun = 0 # Sun的value被设定为0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6

# 访问这些枚举类型可以有若干种方法：
day1 = Weekday.Mon
print(day1)
print(Weekday.Tue)
print(Weekday['Tue'])
print(Weekday.Tue.value)
print(day1 == Weekday.Mon)
print(day1 == Weekday.Tue)
print(Weekday(1))
print(day1 == Weekday(1))

#Weekday(7)
# Traceback (most recent call last):
# ValueError: 7 is not a valid Weekday
for name, member in Weekday.__members__.items():
    print(name, '=>', member)
    
# Practice
class Gender(Enum):
    Male = 0
    Female = 1

class Student(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender
        
# 测试:
bart = Student('Bart', Gender.Male)
if bart.gender == Gender.Male:
    print('测试通过!')
else:
    print('测试失败!')
    
# 使用元类 17-12-17

# class的定义是运行时动态创建的，创建class的方法是使用type()
# type()函数既可返回一个对象的类型，又可以创建出新的类型
# 可通过type()函数创建出Hello类，无需通过class Hello(object)...的定义
def fn(self, name='world'): # 先定义函数
    print('Hello, %s.' % name)
    
# 要创建一个class对象，type()函数依次传入3个参数：
# 1 class的名称 
# 2 继承的父类集合(Python支持多重继承，若仅一个父类以tuple写法)
# 3 class的方法名称与函数绑定，此处把函数fn绑定到方法名hello上
Hello = type('Hello', (object,), dict(hello=fn)) # 创建Hello class
h = Hello()
h.hello()
print(type(Hello))
print(type(h))
# 通过type()函数创建的类和直接写class是identical
# 因Python解释器遇class定义时，仅扫描class定义语法，后调用type()函数创建出class

# metaclass
# 想创建类？就必根据metaclass创类
# 即：先定义metaclass，然后创建类，最后创建实例

# defualt_value metaclass的类名总是以Metaclass结尾，以便表示此为一个metaclass
# metaclass是类的模板，所以必须从`type`类型派生：
class ListMetaclass(type):
    def __new__(cls, name, bases, attrs):
        attrs['add'] = lambda self, value: self.append(value)
        return type.__new__(cls, name, bases, attrs)

# 有了ListMetaclass，定义类时还要使用ListMetaclass来定制类，传入关键字参数metaclass
class MyList(list, metaclass=ListMetaclass):
    pass
# 传入关键字参数metaclass后 在创建MyList时，要通过ListMetaclass.__new__()来创建

# __new__()方法接收到的参数依次是：
# 1 当前准备创建的类的对象；
# 2 类继承的父类集合；
# 3 类的方法集合。
# 4 测试一下MyList是否可以调用add()方法：

#测试一下MyList是否可以调用add()方法：
L = MyList()
L.add(1)
print(L)

# 总会遇到需要通过metaclass修改类定义的。ORM(Object Relational Mapping)典型的例子
# 把关系数据库的一行映射为一个对象，即一个类对应一个表

# 编写底层模块的第一步，就是先把调用接口写出来.比如，使用者如果使用这个ORM框架
# 想定义一个User类来操作对应的数据库表User，我们期待他写出这样的代码：
class User(Model):
    # 定义类的属性到列的映射：
    id = IntegerField('id')
    name = StringField('username')
    email = StringField('email')
    password = StringField('password')

# 创建一个实例：
u = User(id=12345, name='Michael', email='test@orm.org', password='my-pwd')
u.save() #保存到数据库：

# 父类Model和属性类型StringField、IntegerField是由ORM框架提供的
# 剩下的魔术方法比如save()全由metaclass自动完成。metaclass编写复杂，但ORM使用却异常简单。

# 现在，我们就按上面的接口来实现该ORM
# 首先来定义Field类，它负责保存数据库表的字段名和字段类型：
class Field(object):
    def __init__(self, name, column_type):
        self.name = name
        self.column_type = column_type

    def __str__(self):
        return '<%s:%s>' % (self.__class__.__name__, self.name)
        
#在Field的基础上，进一步定义各种类型的Field，比如StringField，IntegerField等等：
class StringField(Field):
    def __init__(self, name):
        super(StringField, self).__init__(name, 'varchar(100)')

class IntegerField(Field):
    def __init__(self, name):
        super(IntegerField, self).__init__(name, 'bigint')
        
# 下一步，就是编写最复杂的ModelMetaclass了：
class ModelMetaclass(type):
    def __new__(cls, name, bases, attrs):
        if name=='Model':
            return type.__new__(cls, name, bases, attrs)
        print('Found model: %s' % name)
        mappings = dict()
        for k, v in attrs.items():
            if isinstance(v, Field):
                print('Found mapping: %s ==> %s' % (k, v))
                mappings[k] = v
        for k in mappings.keys():
            attrs.pop(k)
        attrs['__mappings__'] = mappings # 保存属性和列的映射关系
        attrs['__table__'] = name # 假设表名和类名一致
        return type.__new__(cls, name, bases, attrs)
        
# 以及基类Model：
class Model(dict, metaclass=ModelMetaclass):
    def __init__(self, **kw):
        super(Model, self).__init__(**kw)

    def __getattr__(self, key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Model' object has no attribute '%s'" % key)

    def __setattr__(self, key, value):
        self[key] = value

    def save(self):
        fields = []
        params = []
        args = []
        for k, v in self.__mappings__.items():
            fields.append(v.name)
            params.append('?')
            args.append(getattr(self, k, None))
        sql = 'insert into %s (%s) values (%s)' % (self.__table__, ','.join(fields), ','.join(params))
        print('SQL: %s' % sql)
        print('ARGS: %s' % str(args))







