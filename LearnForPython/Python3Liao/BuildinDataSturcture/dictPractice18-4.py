# -*- coding:UTF-8 -*-

# build dict
D0 = {"id":1, 'info': {'name':'David', 'age':20, 'sex':'M'}}
D1 = {}
D1['id'] = 2
D1['info'] = {'name':'Mick', 'age':17, 'sex':'F'}
D2 = dict( [('id', 3), ('info', {'name':'Lucy', 'age':16, 'sex':'F'}) ])
# key must be string, key=value pairs
D3 = dict( id = 4, info = {'name':'Lucy', 'age':16, 'sex':'F'} )

# other method like update() | pop(key) | D.get(key, defalt)
D1.update(D0)
print( D2.pop('info') )
print( D0.get("id", 0) )
if 'info' in D3:
    print('exist ', D3['info'])
 
# values equal
D = dict( k:0 for k in ['a', 'b'] )
D = dict.fromkeys(['a', 'b'], 0)
print( list( D0.keys() ) )
print( list( D0.values() ))
print( list( D0.items() ))

# dict解析  zip-->together keys and values, it returns a key-vlaue pairs
print( zip( ['a', 'b', 'c'], [1, 2, 3] ) )
D = dict( zip(['a', 'b', 'c'], [1, 2, 3]) )
D = { k:v for k, v in zip(['a', 'b', 'c'], [1, 2, 3]) }
alpha = { i: chr( ord('a')+i-1 ) for i in range(27) if i > 0 }

# 迭代
ks = D.keys()
ks.sort()
for k in ks:
    print(k, '->', D[k])
for k in sorted( D.keys() ):
    print(k, D[k])

# dictionary key exchange with value
def changedict(dic):  
    mydict = {}  
    for key in dic:  
        mydict.update({}.fromkeys(dic[key],key))  
    return mydict

def revert_dict( d ):
	new_dict = { }
	for key in d.keys():
		new_dict[ d[key] ] = key
	return new_dict
    
def time_converter(time):
    # "13:11"->"1:11 p.m."
    #replace this for solution for: ante or post medium
    hours = int( time[0:2])
    minutes = int( time[3:])
    if 0 <= hours <= 11:
        return time + " a.m."    
    elif hours == 12:
        return time + " p.m."
    elif 23>= hours >12:
        return str(hours-12) + time[2:] + " p.m."
        
def checkio(data):
    if len(data) ==  1:
        return data[0]
    elif len(data) > 0:
        return data[0] + checkio(data[1:])
    
    
    
    
    
    