# Object Oriented Programming
# create a class generate a object
# Object = Data + Functions / Property + Behaviour

"""
  OOP程序设计把计算机程序视为一组对象的集合，而每个对象都可
  接收其他对象发过来的消息,并处理这些消息
  计算机程序的执行就是一系列消息在各个对象之间传递
  数据和行为的封装，接口和实现的去耦合
"""
std1 = { 'name': 'Michael', 'score': 98 }
std2 = { 'name': 'Bob', 'score': 81 }

def print_score(std):
    print('%s: %s' % (std['name'], std['score']))
    
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def print_score(self):
        print('%s: %s' % (self.name, self.score))
# instance        
bart = Student('Bart Simpson', 59)
lisa = Student('Lisa Simpson', 87)
bart.print_score()
lisa.print_score()        
        
# Class名大写
"""
  object类是所有类最终都会继承的类
"""
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def get_grade(self):
        if self.score >= 90:
            return 'A'
        elif self.score >= 80:
            return 'B'
        elif self.score >= 60:
            return 'C'
        else:
            return 'C'
# 实例自由绑定属性， 具体的对象
# Python允许对实例变量绑定任何数据
smith = Student('smith', 20)
smith.name = 'Bart Simpson'
smith.score = 90 
lisa = Student('Lisa', 99)
bart = Student('Bart', 59)
print(lisa.name, lisa.get_grade())
print(bart.name, bart.get_grade())

# 访问限制
# 实例的变量名如果以__开头，就变成一个私有变量private
class Student(object):
    """
      外部代码不能随意修改对象内部,
      这样通过访问限制的保护，代码更加健壮。
    """
    def __init__(self, name, score):
        self.__name = name
        self.__score = score
    def get_name(self):
        return self.__name
    def print_score(self):
	    if self.__score >= 60:
                print('A')
    # 允许外部代码修改score 并对参数进行检查，避免无效参数
    def set_score(self, score):
        if 0 <= score <= 100:
            self.__score = score
        else:
            raise ValueError('bad score')
bart = Student('Bart', 59)
# _name类型变量命名外部可见，遵守代码规范
# __name左边双下划线变量被解释翻译为_Student__name,不能直接在外部访问__name
print(bart._Student__name)
# 错误写法 实际上设置了一个__name变量，内部实际为_Student__name
bart.__name = 'New Name'

class Graduate( Student ):
	def __init__(self, name, gender, score):
		self.__name = name
		self.__gender = gender
		self.__score = score
	def get_gender(self):
		return self.__gender
	def set_gender(self, gender):
		if gender == 'male':
			self.__gender = gender
		elif gender == 'female':
			self.__gender =gender
		else:
			raise ValueError("gender error")

# 测试:
bart = Graduate('Bart', 'male', 88)
if bart.get_gender() != 'male':
    print('测试失败!')
else:
    bart.set_gender('female')
    if bart.get_gender() != 'female':
        print('测试失败!')
    else:
        print('测试成功!')
       