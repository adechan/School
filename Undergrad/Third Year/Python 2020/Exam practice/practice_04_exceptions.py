# Curs 4
# exceptions


def ex1():
    try:
        x = 5 / 0
    except:
        print("Exception")  # executes in case of exception
ex1()
print("============")

def ex2():
    try:
        x = 5 / 1
    except:
        print("Exception")  # executes in case of exception
    else:
        print("Else")  # executes if there is NO exception
ex2()
print("============")

# all exceptions are derived from BaseException class.
# types of exceptions: ArithmeticError,..

def ex3(y):
    try:
        x = 5 / y
    except ArithmeticError:
        print("Arithmetic error")
    except:  # always must be after all specified types of errors, else.. ERROR
        print("Generic error")
    else:
        print("No error")
ex3(0)  # --> 5 / 0: Arithmetic error
ex3(1)  # --> 5 / 1: No error
ex3("a")  # --> 5 / "a": Generic error
print("============")

def ex4(y):
    try:
        x = 5 / y
    except:
        print("Error")
    else:
        print("No error")
    finally:  # ALWAYS executes even if there is error or not! MUST be LAST (after else..)
        print("Final")
ex4(1)
ex4(0)
print("============")

def ex5():
    try:
        raise Exception("param1", "param2", "param3")
    except Exception as e:
        params = e.args
        print(len(params))
        print(params[0])
ex5()
print("============")

def ex6():
    try:
        try:
            x = 5 / 0
        except Exception as e:
            print(e)  # --> e = division by 0
            raise  # current exception should be re-raised
    except Exception as e:
        print("Return from raise -> ", e)
ex6()
print("============")

# assert: raise an exception based on the evaluation of a condition
def ex7():
    age = -1
    try:
        assert (age > 0), "Age should be a positive number"
    except Exception as e:
        print(e)
ex7()
print("============")

# MODULES
# SYS: sys.argv[0]: name/path of the script
# OS








