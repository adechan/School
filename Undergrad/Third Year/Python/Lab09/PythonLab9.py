# returns a lists of files containing to_search
# if target is a file: this will be the only file searched
# if target is a directory: all the files found in the directory 
# will be searched
import os;

def is_file(path):
    if os.path.isfile(path):
        return True
    return False

def search_by_content(target, to_search):
    if is_file(target) == True:
        with open(target) as f:
            if to_search in f.read():
                print(to_search + " exists in file " + str(target))

    if is_file(target) == False:
        os.chdir(target)
        for file in os.listdir("."):
            search_by_content(file, to_search)
            target = file

#search_by_content("MeowDir", "ade")

# will return a dictionary with the following fields:
# - full_path - the absolute path of the file
# - file_size - the size of the file
# - file_extension - the file's extension
# - can_read/ can_write : true, false
def get_file_info(file_path):
    dictionary = dict()
    dictionary["full_path"] = os.path.abspath(file_path)
    dictionary["full_size"] = os.path.getsize(file_path)
    dictionary["file_extension"] = file_path.split(".")[1]

    if open(file_path, "w"):
        dictionary["can_write"] = "True"
    else:
        dictionary["can_write"] = "False"

    if open(file_path, "r"):
        dictionary["can_read"] = "True"
    else:
        dictionary["can_read"] = "False"

    return dictionary

#print(get_file_info("meow.txt"))

def write_to_filename(filename):
    f = open(filename, "a")
    for key, value in os.environ.items():
        f.write(key + " " + value +"\n")

    f.close()
    print("Environment was written to file")

#write_to_filename("to_write_here.txt")

# TO DO 4.
def find_files_directories(directory_path):
    for (root, directories, files) in os.walk("."):
        for name in files:
            print(os.path.join(root, name))
        for name in directories:
            print(os.path.join(root, name))


#def prob4():
#    for i in os.listdir(r):
#        path = os.path.join(r, i)
#        if path is dir:
#            #recursive 
#        else:
#            # 

#find_files_directories("PythonLab9")

# TO DO 5. 
def copy_file_into_directory(path_to_file, path_to_directory, buffer_size):
    pass



print(copy_file_into_directory("C:\\Users\\Andreea Rindasu\\source\\repos\\PythonLab9\\meow.txt",  "C:\\Users\\Andreea Rindasu\\source\\repos\\PythonLab9\\MeowDir", 10))

# 6
def recursive(directory_path, list_files = []):
    if is_file(directory_path) == True:
        list_files.append(directory_path)

    if is_file(directory_path) == False:
        os.chdir(directory_path)
        for file in os.listdir("."):
            recursive(file, list_files)
            directory_path = file

    return len(list_files)

#print(recursive("MeowDir"))

def recursive_relative_paths(directory_path, list_files = []):
    
    if is_file(directory_path) == True:
        abs_path = os.path.abspath(directory_path)
        relative_path_index = abs_path.rindex("\\")

        relative_path = abs_path[relative_path_index : len(abs_path)]

        substring_abs_path = abs_path[: relative_path_index]
        substring_abs_path_index = substring_abs_path.rindex("\\")

        relative_path_real = abs_path[substring_abs_path_index : len(abs_path)]

        #find_last_backspace = relative_path_real.rindex("\\")

        #relative_path_r = abs_path[find_last_backspace : len(abs_path)]

        #print(relative_path_real)
        list_files.append(relative_path_real)

    if is_file(directory_path) == False:
        os.chdir(directory_path)
        for file in os.listdir("."):
            recursive_relative_paths(file, list_files)
            directory_path = file

    return list_files

#print(recursive_relative_paths("MeowDir"))


def recursive_abs_paths(directory_path, list_files = []):
    

    if is_file(directory_path) == False:
        abs_path = os.path.abspath(directory_path)

        list_files.append(abs_path)
        
        os.chdir(directory_path)
        for file in os.listdir("."):
            
            recursive_abs_paths(file, list_files)
            directory_path = file

    return list_files

#print(recursive_abs_paths("MeowDir"))

def get_directory_info(directory_path):
    dictionary = dict()

    dictionary["full_path"] = os.path.abspath(directory_path)
    dictionary["total_size_files"]  = recursive(directory_path)
    dictionary["files"] = recursive_relative_paths(directory_path)
    dictionary["dirs"] = recursive_abs_paths(directory_path)

    return dictionary

#print(get_directory_info("MeowDir"))



# RECURSIV: os.walk(..) toate fisierele si directoarele...
# ITERATIV: os.listdir(..) doar directorul curent