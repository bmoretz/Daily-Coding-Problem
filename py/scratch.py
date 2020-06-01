'''T9.

On old cell phones, users typed on a numeric pad and the phone
would provide a list of words that matched these numbers. Each
digit mapped to a set of 0-4 letters. Implement an algorithm
to return a list of matching words, given a sequence of digits.
You are provide a list of valid words (provided in whatever data
structure you'd like). The mapping is shown in the diagram below.

    1       2       3
           abc     def
    4       5       6
   ghi     jkl     mno
   7        8       9
  pqrs     tvu    wxyz
            0

EXAMPLE

Input: 8733
Output: tree, used
'''

from collections import defaultdict

class T9():

    class Dictionary():
        
        class Node():
            def __init__(self, value, parent=None):
                self.value = value
                self.parent = parent
                self.children = defaultdict(list)

        def __init__(self):
            self.root = self.Node(None)

        def insert_word(self, word):
            
            node = self.root

            for letter in [ w for w in word] + ['*']:
                if not letter in node.children:
                    node.children[letter] = self.Node(letter, node)

                node = node.children[letter]
        
        def get_matches(self, letters, nodes=None):

            nodes = [self.root] if not nodes else nodes
            results = []

            for letter in letters:
                for node in nodes:
                    for child in node.children:
                        if child == letter:
                            results += [node.children[letter]]

            return results

    def __init__(self, word_list):
        pad = defaultdict(list)

        pad[2] = ['a', 'b', 'c']
        pad[3] = ['d', 'e', 'f']
        pad[4] = ['g', 'h', 'i']
        pad[5] = ['j', 'k', 'l']
        pad[6] = ['m', 'n', 'o']
        pad[7] = ['p', 'q', 'r', 's']
        pad[8] = ['t', 'v', 'u']
        pad[9] = ['w', 'x', 'y', 'z']
    
        self.pad = pad

        dictionary = self.Dictionary()

        for word in word_list:
            dictionary.insert_word(word)

        self.dictionary = dictionary

    def get_matches(self, num):
        
        if not num: return None

        word_matches = []
        nodes = []

        for digit in str(num):
            letters = self.pad[ int(digit) ]
            nodes = self.dictionary.get_matches(letters, nodes)

        for node in nodes:
            word = ''

            while node.parent:
                word = node.value + word
                node = node.parent
            
            word_matches.append(word)

        return word_matches

words = ['used', 'tree', 'angry', 'world', 'alpha', 'trip', 'usage', 'triangle', 'apple', 'milk']

calc = T9(word_list=words)

results = calc.get_matches(26479)

print(results)