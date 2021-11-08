
from collections import defaultdict

class WordDistances():

    def __init__(self, words=None):
        self.locations = defaultdict(list)
        self.min_distances = defaultdict(int)

        if words:
            self.add_words(words)

    def add_words(self, words):
        for index, word in enumerate(words):
            self.locations[word] += [index]

    def get_distance(self, word1, word2):

        key = (word1, word2)

        if key not in self.min_distances:
            dist = self.shortest_distance(word1, word2)
            self.min_distances[(word1, word2)] = dist
            self.min_distances[(word2, word1)] = dist
        
        return self.min_distances[key]

    def shortest_distance(self, word1, word2):

        ones, twos = self.locations[word1], self.locations[word2]

        deltas = []

        for a in ones:
            for b in twos:
                deltas += [a - b if a > b else b - a]

        return min(deltas) if deltas else None