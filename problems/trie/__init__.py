ENDS_HERE = '#'

class Trie:
    def __init__(self):
        self._trie = {}

    def insert(self, text):
        trie = self._trie

        for char in text:
            if char not in trie:
                trie[char] = {}
            trie = trie[char]
        trie[ENDS_HERE] = True

    def find(self, prefix):
        trie = self._trie
        for char in prefix:
            if char in trie:
                trie = trie[char]
            else:
                return None
        return trie
    
    def _elements(self, d):
        result = []

        for key, value in d.items():
            if key == ENDS_HERE:
                subresult = ['']
            else:
                subresult = [key + suffix for suffix in self._elements(value)]
            result.extend(subresult)

        return result

class Autocomplete1():

    def __init__(self):
        self._words = Trie()

    def insert_words(self, values):

        for val in values:
            self._words.insert(val)
                
    def get_matches(self, prefix):

        matches = self._words.find(prefix)

        suffix = self._words._elements(matches)

        return [prefix + word for word in suffix]

class Autocomplete2():

    def __init__(self):
        self.words = set()

    def insert_words(self, words):
        
        for word in words:
            self.words.add(word)

    def get_matches(self, prefix):

        results = []
        for word in self.words:
            if word.startswith(prefix):
                results.append(word)

        return results
    