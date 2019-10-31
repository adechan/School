import utils


def infinite_loop():

    while True:

        n = input("Enter a value: ")
        int_n = int(n)
        print(utils.process_item(int_n))
