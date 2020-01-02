#!/usr/bin/env python
# Filename: using_file.py

poem = "Programming is funWhen the work is doneif you wanna make your work also fun: use Python!"
path = "poem.txt"

# open for 'w'riting
with open(path,'w') as f: 
    f.write(poem) # write text to file
    f.close() # close the file
    print("{} is saved!".format(path))
    
f = open('poem.txt')
# if no mode is specified, 'r'ead mode is assumed by default
while True: 
    line = f.readline() 
    if len(line)==0: # Zero length indicates EOF 
        break 
    print(line)
# Notice comma to avoid automatic newline added by Python
f.close() 
# close the file