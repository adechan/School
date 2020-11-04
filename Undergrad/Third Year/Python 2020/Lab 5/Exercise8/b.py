# Write a function called multiply_output with one parameter
# named function. The function will return one new function
# which returns the output of the function received multiplied by 2.

def multiply_by_three(x):
    return x * 3

def multiply_output(fn_to_call):
    def augmented_fn(x):
        return 2 * multiply_by_three(x)
    return augmented_fn

augmented_multiply_by_three = multiply_output(multiply_by_three)
x = augmented_multiply_by_three(10)
print(x)