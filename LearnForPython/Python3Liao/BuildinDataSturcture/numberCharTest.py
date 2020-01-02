# -*- coding:UTF-8 -*-

"""1.加减乘除以及内置函数：min(), max(), sum(), abs(), len() 
    math库： math.pi math.e, math.sin math.sqrt math.pow()    
"""  
import math, random
a = 1   # 整形 integer
b = 100

result = []
for i in range(10):
      number = random.randint( a, b )
      # 生成不同的分数
      if number not in result:
            result.append( number )

print("result list->  ", result)
minimum = min(result)  # result找到最小和最大分数
maximum = max(result)
result.remove(minimum)  # 移除最大最小值
result.remove(maximum)
print("after removed->", result)

length = len(result) 
the_sum = sum(result)
average = the_sum / length   # 浮点型, float 求20个数的均值
year =  math.pow(2, 11) - (2**5) + 3 
print( "average=%06.3f, type=%s" % ( average, type(average) ) ) 
print( length, average / year, the_sum / b, the_sum // b ) 
# /为真除法 5/2=2.5 ；//为截断除法，5//2=2类似于C语言的除法
print( random.choice( [1, 2, 3, 4, 5] ), average + random.random() )

""" 数字格式进制
    十进制 八进制 十六进制 二进制 
     int(), oct(), hex(), bin()    
"""
figs = [ 64, 0o11, 0x11, 0b11]
print(figs) # 输出十进制结果 [64, 9, 17, 3]

# eval -> input str transform into digit字符串转数字
print( 'eval: ', eval('64'), eval('0b111'), eval('0x140') )
# int -> str turn to num on base基于进制进行字符串数字转换
print( 'int:  ', int('64'), int('100', 8), int('40', 16) )

# 格式化输出'%o, %x, %b' % (64, 64, 64)
print( 'format printf 64-> ','{0:o}, {1:b}, {2:x}'.format(64, 64, 64) )
digit = int( input("input a digit:") )
print( "{} in different literal:".format( digit, oct(digit), \
         hex(digit),  bin(digit) ) )
         
  
# b_len(x) == x.bit_length()  二进制位数
def b_len( num ):
	return len( bin(num) ) - 2

""" from decimal import Decimal
    deciaml.getcontext().prec = 4 precision
    dNum = Decimal('0.1') + Decimal('1.3')
    temparory prec set
"""
# deciaml 小数
import decimal
with decimal.localcontext() as ctx:
    ctx.prec = 2
    dnum = decimal.Decimal('2.123') / decimal.Decimal('7') 
    
# fraction 分数
from fractions import Fraction
a_frac = Fraction(1, 10) + Fraction(1, 10) - Fraction(2, 10)
a_frac = Fraction(1, 3) + Fraction( 5, 14)
print(a_frac)

def singleNumber(nums):
    """ find single number 
    type   nums: List[int]
    retype     : int
    """ 
    numSet = set(nums)
    for num in numSet:
        if nums.count(num) == 1:
            return num
    else:
        print("We can't found it!")
	        
print( singleNumber([4,1,2,1,2]) )
