from ImdbCorpus import ImdbCorpus
import gensim.models

#for document in corpus:

corpus = ImdbCorpus()
print('Training model...')

model = gensim.models.Word2Vec(sentences = corpus, min_count=10, size=2000, workers=4)
print('Done.')
print('Saving model...')
model.save('imdb_corpus.w2v')
print('Done.')

#model = gensim.models.Word2Vec.load('imdb_corpus.w2v')

input_words = ['dog', 'car', 'gun', 'plant', 'flower', 'film', 'baby', 'meat', 'movie', 'laptop']

for word in input_words:
	print('word: {}'.format(word))
	print('most similar: {}\n'.format(model.wv.similar_by_word(word)[0]))

#for i, word in enumerate(model.wv.vocab):
#    if i == 10:
#        break
#    print(word)