
## 4 arguments: 
# 1, 3 : numbers
# 2 : operation
# 4: output file path

operators = {
	"+" : lambda a, b: a + b,
	"-" : lambda a, b: a - b,
	"/" : lambda a, b: a / b,
	"*" : lambda a, b: a * b,
	"%" : lambda a, b: a % b
	};

import sys
import time

a = sys.argv[1]
a_string = int(a)
b = sys.argv[3]
b_string = int(b)

operation = sys.argv[2]
output_file_path = sys.argv[4]

file = open("{}".format(output_file_path), "a")

result = operators[operation](a_string, b_string)
result_string = str(result)

tobj = time.localtime()
time_string = time.strftime("%Y-%m-%d %H:%M:%S", tobj)

result_to_print = "{} {} {} {} = {}".format(time_string, a_string, operation, b_string, result_string)
print(result_to_print)
file.write(result_to_print)
file.close()
