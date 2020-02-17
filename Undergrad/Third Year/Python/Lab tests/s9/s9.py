
import os

def is_file(path):
    if os.path.isfile(path):
        return True
    return False

def problema1(director):
    extension = ''
    list = []

    dirs = os.listdir(director)

    for file in dirs:  
        #print(file)
        extension = file.split(".")[1] 
        list.append(extension)
        #print(extension)
    
    bad_extension = ['exe']

    ordered_list = sorted(list)

    res = []

    for i in ordered_list:
        if i not in res:
            res.append(i)

    final_res =[]
    for i in res:
        if i not in bad_extension:
            final_res.append(i)
    return final_res

#print(problema1("Meow"))