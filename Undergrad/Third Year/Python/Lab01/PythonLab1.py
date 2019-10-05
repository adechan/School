## Exercitiul 1
## Find the greatest common divisor of two 
## numbers read from the console 

def gcd(a, b):
    if (b == 0):
        return a;
    else:
        return gcd(b, a % b);

print("Give a number: ")
a = int(input());
print("Give another number: ")
b = int(input());


print("Gcd of " + str(a) +  " and " + str(b) + " is: " , end  = "")
print (gcd(a, b));

## OR
## Find the greatest common divisor of multiple
## numbers read from the console 

#  def gcd2(*numbers):
#      return n;

def gcd2(a, b):
    if (b == 0):
        return a
    else:
        return gcd(b, a % b)

print("Give me multiple numbers: ")
x = list(map(int, input().split()))
length = len(x)
print(length)

result = x[0]
for i in range(0, len(x), 1):
    print(i)
    result = gcd2(result, x[i])

print("Gcd of " + str(x) + " is ", end = "")
print(result)


## Exercitiul 2
## Write a script that calculates how many vowels
## are in a string

def countVowels(string):
    num_vowels = 0; 
    for character in string:
        if character in "aeiouAEIOU":
            num_vowels = num_vowels + 1
    return num_vowels;

print("Give a sentence: ");
string = input();

print("Number of vowels is: " + str(countVowels(string)));

## Exercitiul 3
## Write a script that receives two strings and prints the 
## number of occurrences of the first string in the second

def numberOfOccurences(string1, string2):
    num_occurences = 0;
    for character in string1: 
        if character in string2:
            num_occurences = num_occurences + 1;

    return num_occurences;

string1 = input();
string2 = input();

print ("Number of occurences is: " + str(numberOfOccurences(string1, string2)));

## Exercitiul 4
## Write a script that converts a string of characters written
## in UpperCamelCase into lowercase_with_undercores
## A -> a_

def upperCaseToLowerCase(string):
    is_first = True;
    result = ""

    for character in string:   
      if is_first:
            is_first = False
            result += character.lower();
      else:
            if character == character.lower():
                 result += character
            else: 
                 result += "_{}_".format(character.lower())
                 ## result += f"_{c.lower()}"
    return result;

print (upperCaseToLowerCase("CameL"));

## Exercitiul 5
## Given a square matrix of characters write a script that prints
## the string obtained by going through the matrix in spiral order

def spiralPrint(end_row, end_column, a):
    start_row = 0
    start_column = 0    

    while (start_row < end_row and start_column < end_column): 
           
        # start_column = 0; end_column = 3 ( | . | . | . | )
        # a[0][i], i = 0, 1, 2
        for i in range(start_column, end_column): 
            print(a[start_row][i], end = " ") 
              
        # start_row = 1
        start_row += 1
 
        # start_row = 1; end_row = 3 
        # a[i][2], i = 1, 2
        for i in range(start_row, end_row): 
            print(a[i][end_column - 1], end = " ") 
             
        # end_column = 2
        end_column -= 1
  
        # start_row = 1, end_row = 3
        # end_column = 1, start_column = -1 
        # a[2][i], i = 1, 0
        if (start_row < end_row):  
            for i in range(end_column - 1, (start_column - 1), -1) : 
                print(a[end_row - 1][i], end = " ") 
           
            # end_row = 2
            end_row -= 1
          
        # start_column = 0; end_column = 2
        # end_row = 2, start_row = 0
        # a[i][0], i = 2, 1, 0
        if (start_column < end_column): 
            for i in range(end_row - 1, start_row - 1, -1) : 
                print(a[i][start_column], end = " ") 
              
            # start_column = 1
            start_column += 1
  
# Driver Code 
a = [ [1, 2, 3, 4, 5, 6], 
      [7, 8, 9, 10, 11, 12], 
      [13, 14, 15, 16, 17, 18] ] 
        
R = 3; C = 6
spiralPrint(R, C, a) 
