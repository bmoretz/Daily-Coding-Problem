"""
Shuffle.

Write a method to shuffle a deck of cards. It must be a perfect shuffle --
in  other words, each of the 51! permutations of the deck has to be equally
likely. Assume that you are given a random number generator which is perfect.
"""

from enum import Enum
from random import randint

class Suite(Enum):
    Hearts = 1
    Aces = 2
    Spades = 3
    Clubs = 4

class Deck():

    def __init__(self):
        self.cards = self._get_deck()
    
    def _get_suite(self, suite : Suite ):
        
        face = ['J', 'Q', 'K', 'A']
        num = [str(n) for n in range(2, 11)]

        cards = []

        for c in num + face:
            cards += [(suite.name, c)]
            
        return cards

    def get(self):
        return self.cards

    def get_rand(self, minimum, maximum):
        # assume perfect random uniform
        return randint(minimum, maximum)

    def _get_deck(self):
        
        deck = []

        for suite in Suite:
            deck += self._get_suite(suite)

        return deck

    def shuffle(self):
        
        n = len(self.cards)

        for index in range(n):
            # uniform draw (0, 51)
            draw = self.get_rand(0, n - 1)

            # swap k & i
            self.cards[index], self.cards[draw] = \
                self.cards[draw], self.cards[index]