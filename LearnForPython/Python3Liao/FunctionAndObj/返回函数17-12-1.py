# 返回函数

# 可变参数的求和函数
def calc_sum(*args):
    ax = 0
    for n in args:
        ax = ax + n
    return ax
    
# 不需要立刻求和，在后面代码中据需要再计算
def lazy_sum(*args): 
    def sum(): # “闭包（Closure）”程序结构
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum
# 调用lazy_sum()时，返回的并不是求和结果，而是求和函数
f = lazy_sum(1, 3, 5, 7, 9)
# 闭包(Closure)-在函数lazy_sum中又定义了函数sum
# 内部函数sum可以引用外部函数lazy_sum的参数和局部变量
# 当lazy_sum返回函数sum时，相关参数和变量都保存在返回的函数中

# 调用函数f时，才真正计算求和
print(f())
# 即使传入相同的参数
# 当调用lazy_sum()时，每次调用都会返回一个新的函数
f1 = lazy_sum(1, 3, 5, 7, 9) # 好比两个指针，指向不同的函数
f2 = lazy_sum(1, 3, 5, 7, 9)

# 闭包
# 当一函数返回了一个函数后，其内部的局部变量还被新函数引用
# 返回的函数并没有立刻执行，而是直到调用了f()才执行
def count():
    fs = []
    for i in range(1, 4):
        def f():
             return i*i
        fs.append(f)
    return fs
# f1() = f2() = f3() = 9
# 原因就在于返回的函数引用了变量i，但它并非立刻执行
# 等到3个函数都返回时，它们所引用的变量i已变成3，最终结果故为9
f1, f2, f3 = count()

# !返回函数不要引用任何循环变量，或者后续会发生变化的变量。
# 一定要引用循环变量，就再创建一个函数
# 用该函数的参数绑定循环变量当前的值，无论该循环变量后续如何更改
# 已绑定到函数参数的值不变
def count():
    def f(j):
        def g():
            return j*j
        return g
    fs = []
    for i in range(1, 4):
        fs.append(f(i)) # f(i)立刻被执行，因此i的当前值被传入f()
    return fs
# 返回的该函数并未执行，返回函数中不要引用任何可能会变化的变量
f1, f2, f3 = count()
print(f1())
print(f2())
print(f3())

# Pracice
def createCounter():
    i = 0
    def counter():
        nonlocal i
        i = i + 1
        return i
    return counter

# 测试:
counterA = createCounter()
print(counterA(), counterA(), counterA(), counterA(), counterA()) # 1 2 3 4 5
counterB = createCounter()
if [counterB(), counterB(), counterB(), counterB()] == [1, 2, 3, 4]:
    print('测试通过!')
else:
    print('测试失败!')
