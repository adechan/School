
## configure API for Wordnet
## 1.

from nltk.corpus import wordnet
from nltk.corpus.reader import NOUN
syns = wordnet.synsets("cat")
#print(syns)

## 2.
## identify the first hypernym for a word
def first_hypernym(word):
	syns = wordnet.synsets(word)
	if len(syns) > 0 and syns[0].hypernyms():
		return syns[0].hypernyms()[0]
	return None
#print(str(first_hypernym("cat")))

## identify the first sense for a word
def first_sense(word):
	syns = wordnet.synsets(word)
	if len(syns) > 0 and syns[0].lemmas():
		return syns[0].lemmas()[0]
	return None
#print(str(first_sense("cat")))


## returns True/False if the word is noun or not
def is_noun(word):
	syns = wordnet.synsets(word, NOUN)
	if len(syns) == 0:
		return False
	return True
#print(is_noun("cook"))


import re

## file in english
## find all the words from the file 
## find all the nouns 
## if its noun: replace the noun with its hypernym of the first sense
## if not: dont replace

def change_noun_to_hypernym(word):
	if is_noun(word):
		sense = first_sense(word)
		if not sense:
			return word

		hypernym = first_hypernym(sense.name())
		if not hypernym:
			return word

		return hypernym.name().split(".")[0].upper()
	else:
		return word

def change_to_first_synset_hypernym(file):
	words = []
	regex = re.compile("[a-zA-Z]+")

	with open(file) as f:
		backup = f.read()
		matches = re.findall(regex, backup)
		for match in matches:
			words.append(match)

	# takes each element in a list
	# and converts it to something given by the function
	# => if its a noun: converts to its hypernym
	# => if its not a noun: its the identity function => returns the word
	modified_words = list(map(change_noun_to_hypernym, words))

	open(file, 'w').close()

	with open(file, 'w') as f:
		f.write(' '.join(modified_words))

	#return ' '.join(modified_words)
	return backup

print(change_to_first_synset_hypernym("file.txt"))





