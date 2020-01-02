#  -*- coding: utf-8 -*-
# 装饰器 Decorator --> 增强函数的功能， 函数也是一个对象，而且函数对象可以被赋值给变量
# 所以，通过变量也能调用该函数。

def now():
    print('2017-12-2')
fun1 = now
fun1()
# 函数对象有一个__name__属性，可以拿到函数的名字
print(now.__name__)
print(fun1.__name__)

# decorator就是一个返回函数的高阶函数
"""
@decorator
def func():
    pass
解释器解释为：
func = decorator(func)
"""
def hello(fn):
    def wrapper():
        print("wrapping now, %s" % fn.__name__)
        fn()
        print("goodby, %s" % fn.__name__)
    return wrapper

@hello
def foo():
    print("i am foo")   
foo() # 解释为：foo = hello(foo),被执行的语句
   
# 所以定义一个能打印日志的decorator如下：
def log(func):
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper
# 观察上面的log，因为它是一个decorator
# 所以接受一个函数作为参数，并返回一个函数

#我们要借助Python的@语法，把decorator置于函数的定义处：
@log
def now_today():
    print('2015-3-25')
now_today()
# 把@log放到now()函数的定义处，相当于执行了
now_today = log(now_today)
# 因log()是一个decorator，返回一个函数
# 故原来的now_today()函数仍存在，只是现在同名now_today变量指向了新的函数
# 于是调用now_today()将执行新函数，即在log()函数中返回的wrapper()函数。

# 若decorator本身需要传入参数，就需编写一个返回decorator的高阶函数
def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator

@log('execute')
def now():
    print('2015-3-25')
now() # it seem like --> now = log('execute')(now)
print(now.__name__) #'wrapper'
    
# 需要把原始函数的__name__等属性复制到wrapper()函数中
import functools
def log1(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator
    
# Practice
import time, functools
def metric(fn):
    def warpper(*args, **kw):
        start = time.time()
        print('%s executed in %s ms' % (fn.__name__, (time.time()-start)*1000))
        return fn(*args, **kw)
    return warpper
# 测试
@metric
def fast(x, y):
    time.sleep(0.0012)
    return x + y
@metric
def slow(x, y, z):
    time.sleep(0.1234)
    return x * y * z;

f = fast(11, 22)
s = slow(11, 22, 33)
if f != 33:
    print('测试失败!')
elif s != 7986:
    print('测试失败!')


def mylog(fn):
	def wrapper( *args, **kw ):
		print("begin call %s" % fn.__name__)
		fn(*args, **kw)
		print("end call %s" % fn.__name__)
	return wrapper
@mylog
def write():
	print("writing")
write()

def logs(text=""):
	def decorator(fn):
		def wrapper( *args, **kw ):
			print("begin call %s" % fn.__name__)
			print("text", fn.__name__)
			fn(*args, **kw)
			print("end call %s" % fn.__name__)
		return wrapper
	return decorator
# 外层默认参数
@logs('execute')
def now():
	print("2011-1-1")
now()

# simulate flask
class app():
	def __init__( self, rule ):
        self.rule = rule # 请求url
        
    def route( self, func_url ):
        """ route for url from flask
            bind the url with the model
          """
        def decorator( func ):
            def wrapper( *args, **kw ):
                if self.rule == func_url:
                    print("execute",func.__name__)
                    return func(*args, **kw)
            return wrapper
        return decorator

app = app("user/")
@app.route('user/')
def user():
    return "<h1>Model</h1>"
user() # end flask

# decorator test, decorator with parameter
def makeHtmlTag(tag, *args, **kwds):
    def real_decorator(fn):
        css_class = " class='{0}'".format(kwds["css_class"]) \
                                     if "css_class" in kwds else ""
        def wrapped(*args, **kwds):
            return "<"+tag+css_class+">" + fn(*args, **kwds) + "</"+tag+">"
        return wrapped
    return real_decorator
 
@makeHtmlTag(tag="b", css_class="bold_css")
@makeHtmlTag(tag="i", css_class="italic_css")
def hello():
    return "hello world"
 
print( hello() )

# Partial Func偏函数
# 把一个函数的某些参数给固定住（也就是设置默认值,返回一个新的函数
import functools
int2 = functools.partial(int, base=2)
int2('1000000')
# 当传入：
max2 = functools.partial(max, 10)
# 实际上会把10作为*args的一部分自动加到左边，也就是：

max2(5, 6, 7)
# 相当于
args = (10, 5, 6, 7)
max(*args)
# 当函数的参数个数太多，需要简化时，使用functools.partial可以创建一个新的函数，
# 这个新函数可以固定住原函数的部分参数，从而在调用时更简单
