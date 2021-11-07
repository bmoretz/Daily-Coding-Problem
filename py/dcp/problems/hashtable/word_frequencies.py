'''Word Frequencies.

Design a method to find the frequency of occurrences of any given word
in a book. What if we were running this algorithm multiple times?
'''

from collections import defaultdict
from string import ascii_letters

def word_frequency(text):

    if text == None: return None

    cleaned = ''

    for char in text:     
        if char == ' ' or char in ascii_letters:
            cleaned += char

    words = cleaned.lower().split(' ')

    freq = defaultdict(int)    

    for word in words:
        freq[word] += 1

    return freq