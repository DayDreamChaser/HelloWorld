#!/usr/bin/env python3
#  -*- coding: utf-8 -*-
' a test module ' # 表示模块的文档注释__doc__

__author__ = 'Michael Liao'
# 第1行可让此文件直接在Unix/Linux/Mac上运行
# 以上为标准文件模板
# 包导入 __init__.py，包作为模块的顶层
import sys

def test():
    args = sys.argv
    # sys模块有一个argv变量，用list存储了命令行的所有参数
    # argv至少有一个元素，因第一个参数永远是该.py文件的名称
    if len(args)==1:
        print(args[0])
    elif len(args)==2:
        print('Hello, %s!' % args[1])
    else:
        print('Too many arguments!')

# 当我们在命令行运行hello模块文件时，Python解释器把一个
# 特殊变量__name__置为__main__
# 这种if测试可以让一个模块通过命令行运行时执行一些额外的代码
if __name__=='__main__':
    test()
    
# 作用域
# 正常的函数和变量名是公开的（public），可被直接引用，如：abc
# 类似__name__这样的变量是特殊变量
# 类似_xxx和__xxx这样的函数或变量就是非公开的（private）
_age_ = 50 # 从编程习惯上不应该引用private函数或变量

# private函数或变量不应该被别人引用，那它们有什么用呢？请看例子：
def _private_1(name):
    return 'Hello, %s' % name

def _private_2(name):
    return 'Hi, %s' % name
# 我们在模块里公开greeting()函数，而把内部逻辑用private函数隐藏起来
def greeting(name):
    if len(name) > 3:
        return _private_1(name)
    else:
        return _private_2(name)

# 封装的思想，private只由内部函数操作，由内部函数调用
# 外部不需要引用的函数全部定义成private
# 只有外部需要引用的函数、接口才定义为public

# pip3 install flask
# 模块搜索路径
import mymodule
# 当我们试图加载一个模块时，Python会在指定的路径下搜索对应的.py文件
# 如果找不到，就会报错：ImportError: No module named mymodule
import sys
print(sys.path)
# 默认情况下，Python解释器会搜索当前目录、所有已安装的内置模块和第三方模块
# 搜索路径存放在sys模块的path变量中

# 修改搜索目录
# 1 直接修改sys.path，添加要搜索的目录：
import sys
sys.path.append('targetd/path')
# 此法在运行时修改，运行结束后失效。

# 2 设置环境变量PYTHONPATH
# 设置方式与设置Path环境变量类似，注意只需要添加你自己的搜索路径
