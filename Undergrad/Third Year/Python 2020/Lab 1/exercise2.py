# Write a script that calculates how many vowels are in a string.

def isVowel(letter):
    vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    if letter in vowels:
        return True
    else:
        return False

def countVowels(string):
    count = 0
    for letter in string:
        if isVowel(letter):
            count = count + 1
    return count

print(countVowels("abceA"))