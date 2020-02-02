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
    
class Autocomplete1():

    def __init__(self):
        self._words = Trie()

    def insert_words(self, values):

        for val in values:
            self._words.insert(val)

    def get_values(self, matches):

        def words():
            for key, value in matches.items():
                if isinstance(value, dict):
                    for subkey, subvalue in self.get_values(value).items():
                        yield key + subkey, subvalue
                else:
                    yield key if key != ENDS_HERE else '', ''

        return dict(words())
                
    def get_matches(self, prefix):

        matches = self._words.find(prefix)

        results = []
        for word in self.get_values(matches).keys():
            results.append(prefix + word)
        return results