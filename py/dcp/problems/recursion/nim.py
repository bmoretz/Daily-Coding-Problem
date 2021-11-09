"""
Play Nim.

The game of Nim is played as follows. Starting with three heaps, each containing a variable number of items, two players take turns removing one or more 
items from a single pile. The player who eventually is forced to take the last stone loses. For example, if the initial heap sizes are 3, 4 and 5, a game could
be played as shown below:

A   B   C   | Action
3   4   5   | Player 1 take 3 items from B
3   1   5   | Player 2 take 2 items from C
0   1   3   | Player 1 take 3 items from A
0   1   3   | Player 2 take 3 items from C
0   1   0   | Player 1 take 1 items from A
0   0   0   | Player 1 loses

Given a list of non-zero starting values [a, b, c], and assuming optimal play, determine whether the first player has a forced win.
"""

heaps = [3, 4, 5]

def nim1(heaps):

    def update(heaps, pile, items):
        heaps = list(heaps)
        heaps[pile] -= items
        return tuple(heaps)

    def get_moves(heaps):
        moves = []

        for pile, count in enumerate(heaps):
            for i in range(1, count + 1):
                moves.append(update(heaps, pile, i))

        return set(moves)
    
    def nim(heaps):
        if heaps == (0, 0, 0):
            return True

        moves = get_moves(heaps)

        return any([nim(move) != True for move in moves])
    
    return nim(heaps)

def nim2(heaps):

    a, b, c = heaps

    if a == b == c == 1:
        return False

    return a ^ b ^ c != 0