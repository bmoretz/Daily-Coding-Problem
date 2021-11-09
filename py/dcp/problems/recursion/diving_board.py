'''Diving Board.

You are building a diving board by placing a bunch of planks of wood end-to-end.
There are two types of planks, one of length shorter and one of length longer. You
must use exactly K plans of wood. Write a method to generate all possible lengths
for the diving board.
'''

from enum import Enum

class piece(Enum):
    Short = 1
    Long = 2

def diving_boards1(k):
        
    def get_boards(k, lengths={}):

        if k == 0: return [0]

        lengths[k] = []

        for plank in [piece.Short, piece.Long]:
            
            if k-1 not in lengths:
                lengths[k-1] = get_boards(k-1, lengths)
            
            cur = [plank.value + p for p in lengths[k-1]]

            if cur not in lengths[k]:
                lengths[k] += cur
        
        return lengths[k]

    if k == None: return None

    return get_boards(k)