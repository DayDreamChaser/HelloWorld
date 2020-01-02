# 1 使用__slots__限制类属性
class Student(object):
    pass
# bond a attribute to instance
s = Student()
s.name = 'Rudy'
print(s.name)
# bond a function
def set_age(self, age): # define a fucntion
    self.age = age
    
from types import MethodType
s.set_age = MethodType(set_age, s)
s.set_age(22)
print(s.age)

# so dynamic bond, bond fucntion for Class
# 在运行中给类绑定功能
def set_score(self, score):
    self.score = score
Student.set_score = set_score
s.set_score(90)
print(s.score)

# use __slot__ constrain the attr of instance 
class Learner(object):
    __slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
l = Learner() 
l.name = 'Exellent'# 限制绑定属性，否则会引起AttributeError
l.age = 16  # l.score = 90 -> setattr( l, 'score', 90)

#__slot__只限制当前类实列，对继承子类不起作用，除非在子类也定义
class GraduateStudent(Learner):
    pass
g = GraduateStudent()
g.score = 100
print("g score =",g.score)

#**********************************************#

# 2 使用@property，简化接口，不直接暴露属性
# 为了限制score的范围，可以通过一个set_score()方法来设置成绩
class Student(object):
    """既能检查参数，又可以用类似属性的方法代替访问行为
    Python内置的@property装饰器就负责把一个方法变成属性调用
    """
    @property # getter
    def score(self):
        return self._score
    
    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
"""把一个getter方法变成属性，只需要加上@property就可以了，
此时@property本身又创建了另一个装饰器@score.setter
负责把一个setter方法变成属性赋值
"""
s = Student() 
s.score = 60 # OK，实际转化为s.set_score(60)
print(s.score) # OK，实际转化为s.get_score()
#s.score = 9999  # raise error means
#该属性很可能不是直接暴露的，而是通过getter/setter实现的

# 定义只读属性，仅有getter方法，而没有setter
class Student(object):
    @property
    def birth(self):
        return self._birth
    @birth.setter
    def birth(self, value):
        self._birth = value
    @property
    def age(self):
        return 2019 - self._birth # depends on birth
#上面的birth是可读写属性，而age就是一个只读属性
"""让调用者写出简短的代码，同时保证对参数进行必要的检查，这样，程序运行时就减少了出错的可能性。
"""
# Practice
class Screen(object):
    @property #getter
    def width(self):
        return self._width
    @width.setter
    def width(self, value):
        if not isinstance(value, int):
            raise ValueError("Width must be an integer!")
        if value < 0 or value > 10000:
            raise ValueError("Width must in [0,10000]")
        self._width = value
            
    @property #getter
    def height(self):
        return self._height
    @height.setter
    def height(self, value):
        if not isinstance(value, int):
            raise ValueError("Height must be an integer!")
        elif value < 0 or value > 10000:
            raise ValueError("Height must in [0,10000]")
        self._height = value
            
    @property
    def resolution(self):
        return self._width * self._height
            
# 测试:
s = Screen()
s.width = 1024
s.height = 768
print('resolution =', s.resolution)
if s.resolution == 786432:
    print('测试通过!')
else:
    print('测试失败!')
