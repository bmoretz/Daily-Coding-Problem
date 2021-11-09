
'''Master Mind.

The Game of Master Mind is played as follows:

The computer has four slots, and each slot will contain a ball that is red (R),
yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (
slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).

You, the user, are trying to guess the solution. You might, for example,
guess YRGB.

When you guess the correct color for the correct slot, you get a "hit." If you
guess a color that exists but is in the wrong slot, you get a "pseudo-hit." Note
that a slot is a hit can never count as a pseudo-hit.

For example, if the actual solution is RGBY and you guess GGRR, you have
one hit and one pseudo-hit. Write a method that, given a guess and a
solution, returns the number of hits and pseudo-hits.
'''

from random import uniform, randint, seed
from enum import Enum

class MasterMind():

    class Colors(Enum):
        Red = 1
        Blue = 2
        Green = 3
        Yellow = 4
    
    def to_guess(self, colors):

        guess = []
        
        for col in colors:
            guess.append(self.Colors(col))

        return guess

    def __init__(self, s=1234):
        seed(s)
        self.solution = self._gen_solution()

    def peek(self):
        return self.solution

    def _gen_solution(self):

        sln = []

        for _ in range(4):
            sln.append( self.Colors(randint(1, 4)) )
        
        return sln

    def guess(self, solution):
        
        hits = 0
        partial_candidates, remaining = [], []

        for index in range(4):
            
            current = solution[index]

            if self.solution[index] == current:
                hits += 1
            else:
                if current not in partial_candidates:
                    partial_candidates += [current]
                if self.solution[index] not in remaining:
                    remaining += [self.solution[index]]
                
        pseudos = 0

        for candidate in partial_candidates:

            if candidate in remaining:
                pseudos += 1

        return (hits, pseudos)