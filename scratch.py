from problems.trie import Trie

from problems.trie import Autocomplete1

'''8.1
Implement Autocomplete System

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings:

[dog, deer, deal]

return [deer, deal]

'''

values, search = ['dog', 'deer', 'deal'], "de"

ac = Autocomplete1()
ac.insert_words(values)

print( ac.get_matches(search) )