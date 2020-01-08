import os
import random
import re
from gensim import utils

class ImdbCorpus(object):
	def __init__(self):
		self.__documents = []
		train_data_path = 'C:\\Users\\Andreea Rindasu\\source\\repos\\AIHomework11\\train_samples.dat'

		with open(train_data_path) as f:
			for line in f:
				self.__documents.append(line)

		random.shuffle(self.__documents)

	def __len__(self):
		return len(self.__documents)

	# gensim's Word2Vec model expects its data as an iterable range
	def __iter__(self):
		for document in self.__documents:
			yield utils.simple_preprocess(document)
