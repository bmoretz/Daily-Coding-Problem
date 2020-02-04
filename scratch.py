'''Implement an autocomplete system. 

That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
'''

values = ['dog', 'deer', 'deal', 'deed']

ENDS_HERE = '#'

class Autocomplete3:

    def __init__(self):
        self.words = {}

    def insert(self, word : str):
        
        level = self.words

        for char in word:
            if char not in level: 
                level[char] = {}
            level = level[char]
        level[ENDS_HERE] = '#'

    def expand(self, values : dict):

        results = []

        for key, value in values.items():

            if key == ENDS_HERE:
                subresult = ['']
            else:
                subresult = [key + suffix for suffix in self.expand(value)]
            
            results.extend(subresult)

        return results

    def find(self, prefix : str):

        level = self.words

        for char in prefix:
            if char in level:
                level = level[char]

        return [prefix + word for word in self.expand(level)]

lookup = Autocomplete3()

for val in values:
    lookup.insert(val)

results = lookup.find("de")
print(results)
