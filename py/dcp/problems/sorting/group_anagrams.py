'''Group Anagrams.

Write a method to sort an array of strings so that all the anagrams are
next to each other.
'''

def group_anagrams1(words : list[str]) -> list[str]:
    """
    O(N logN ) solution.

    Args:
        words (list[str]): words

    Returns:
        list[str]: sorted by anagrams
    """
    def get_word_value(word):

        value = 0

        for letter in word.lower():
            
            if letter == ' ': continue

            value += ord(letter)

        return value

    if words == None: return None

    lookup = {}

    for word in words:
        lookup[word] = get_word_value(word)

    position = sorted((value, key) for (key, value) in lookup.items())

    return [value for (_, value) in position]

from collections import defaultdict

def group_anagrams2(words : list[str] ) -> list[str]:
    """
    O(n) solution

    Args:
        words (list[str]): words

    Returns:
        list[str]: sorted by anagrams
    """
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