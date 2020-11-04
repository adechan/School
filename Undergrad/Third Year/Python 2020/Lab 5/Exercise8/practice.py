def pretty_string(x):
    return 'Helllo: ' + x

def modify_pretty_string(function):
    def function_impostor(x):
        y = function(x)
        y += '. Nice to meet you'
        return y

    return function_impostor


x = modify_pretty_string(pretty_string)
y = x('Andreea Dr Meow Meow')
print(y)
