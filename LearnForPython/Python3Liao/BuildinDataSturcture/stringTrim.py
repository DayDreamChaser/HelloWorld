# -*- coding:UTF-8 -*-
#切片 strip
def trim0(s):
    if not ' ' in s:
        return s
    #" if s == '':
    # '    ' s.isspace()
    elif s.count(' ') == len(s):
        return ''
    # 'hello   '
    elif s[0] != ' ' and s[-1] == ' ':
        pos = s.index(' ') #s.find(' ') 
        return s[:pos]
    # '   hello'
    elif s[0] == ' ' and s[-1] != ' ':
        s_num = s.count(' ')
        return s[s_num:]     
    # '  hello  '
    else:
        return s.replace(' ', '')
        
#正常版
def trim(s):  
    # '' or 'hello'
    if not ' ' in s:
       return s
    # '     '
    elif s.isspace():
       return ''
    # '   hello' or 'hello  ' or '  hello  ' 
    else:
        return s.replace(' ', '') # just need thiis line
        
#递归版        
def trim1(s):  
    # return '' or 'hello' as basic condition
    if not ' ' in s:
        return s
    elif s[0] == ' ':
        return trim1(s[1:])
    elif s[-1] == ' ':
        return trim1(s[:-1])
#循环版
def trim2(s):
    if s == '' or s.isspace():
        return ''
    while s[0] == " ":
        s = s[1:]
    while s[-1] == " ":
        s = s[:-1]
    return s

# 测试:
def testTrim( trim ):
    if trim('hello  ') != 'hello':
        print('测试失败!')
    elif trim('  hello') != 'hello':
        print('测试失败!')
    elif trim('  hello  ') != 'hello':
        print('测试失败!')
    elif trim('') != '':
        print('测试失败!')
    elif trim('    ') != '':
        print('测试失败!')
    else:
        print('测试成功!')
    
testStr = "init start"
while testStr != "-":
    print( trim2(testStr) )
    testTrim( trim2 )
    testStr = input()