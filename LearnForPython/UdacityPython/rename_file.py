# rename file
import os
def rename_files( path, file_str ):
    #(1) get file names from a folder
    file_path = path
    file_list = os.listdir(file_path)
    print(file_list)
    
    saved_path = os.getcwd()
    print("Current Working Directory is" + saved_path)
    os.chdir(file_path)
    
    #(2) for each file, rename filename
    i = 1
    for file_name in file_list:
        os.rename(file_name, file_str + file_name[5:])
        #os.rename(file_name, name + str(i) + ".jpg")
        i += 1
    os.chdir(saved_path)
    print("Name change already!")
   
file_str =  " "
path = "C:\\Users\\Administrator\\Desktop\\hfhtmlcss\\chapter5\\mypod\\Fennie Yuen"   

rename_files( path, file_str )