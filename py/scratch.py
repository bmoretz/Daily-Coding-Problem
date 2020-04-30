'''Group Anagrams.

Write a method to sort an array of strings so that all the anagrams are
next to each other.
'''

def group_anagrams2(words):
    from collections import defaultdict
    from string import ascii_lowercase

    def get_word_value(word):

        value = 0

        for letter in word.lower():
            
            if letter == ' ': continue

            value += ord(letter)

        return value

    if words == None: return None

    lookup = defaultdict(list)

    for word in words:
        key = get_word_value(word)

        lookup[key].append( word )

    ordered = [ item for sublist in lookup.values() for item in sublist ]

    return ordered

words = ['A gentleman', 'The eyes', 'Conversation', 'quiet', 'real fun', 'Dormitory', 'dog', 'Elegant man', 'glisten', 'They see', 'cat', 'silent', 'funeral', 'Dirty room', 'Voices rant on']

results = group_anagrams2(words)
        
print(results)

