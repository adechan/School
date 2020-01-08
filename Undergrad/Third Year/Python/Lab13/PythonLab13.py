
## Ex 1 
# Create a function that receives two parameters: 
# a_path and ext. The script will add all files from 
# the a_path folder that have the extension ext to a zip 
# archive named the.zip. Optionally: a third parameter may 
# specify the full arhive path.
import os 
import zipfile

def exercise1(a_path, ext):
	files = []
	zf = zipfile.ZipFile("Python.zip", "w", zipfile.ZIP_DEFLATED)
	os.chdir(a_path)
	for file in os.listdir(a_path):
		if file[-4:] == ext:
			files.append(file)
			zf.write(file)

	zf.close()
	return files

#print(exercise1("C:/Users/Andreea Rindasu/source/repos/PythonLab13/exp_file", ".ext"))

## Ex 2 
# Create a function that receives one parameter: a_path. 
# If a_path is a valid zip archive the function will return 
# a list containing all file names inside. If a_path is not 
# a valid zip archive the function will return False.

def exercise2(a_path):
	file_names_list = []

	z = zipfile.ZipFile(a_path)
	if a_path[-4: ] != ".zip":
		return False

	file_names_list.append(z.namelist())

	flat_list = []
	for sublist in file_names_list:
		for item in sublist:
			flat_list.append(item)

	return flat_list

#print(exercise2("C:/Users/Andreea Rindasu/source/repos/PythonLab13/Python.zip"))
