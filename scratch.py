from collections import defaultdict, deque

from problems.graph import IGraph, find_path
from problems.graph.adj_list_graph import ALGraph
from problems.graph.adj_mat_graph import AMGraph

''' Beat snakes and ladders.

Snakes and Ladders is a game played on a 10x10 board, the goal of which is getting from square 1 to square 100. On each turn
players will roll a six-sided die and move forward a number of spaces equal to the result. If they land on a square that represents
a snake or ladders, they will be transported ahead or behind, respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenince, here are the squares representing snakes and ladders, and their outcomes:
'''

snakes = {17 : 13, 52 : 29, 57 : 40, 62 : 22, 88 : 18, 95 : 51, 97 : 79}
ladders = {3 : 21, 8 : 30, 28 : 84, 58 : 77, 75 : 86, 80 : 100, 90 : 91}

n_squares = 100

''' ***************** '''

def minimum_turns1(snakes, ladders, n_squares):

    def build_board(snakes, ladders, n_squares):
        board = {square : square for square in range(1, n_squares + 1)}

        for start, end in snakes.items():
            board[start] = end

        for start, end in ladders.items():
            board[start] = end

        return board

    board = build_board(snakes, ladders, n_squares)
    
    start, end = 0, 100
    turns = 0

    path = deque([(start, turns)])
    visited = set()

    while path:
        square, turns = path.popleft()

        for move in range(square + 1, square + 7):
            if move >= end:
                return turns + 1

            if move not in visited:
                visited.add(move)
                path.append((board[move], turns + 1))

min_turns = minimum_turns1(snakes, ladders, n_squares)

print(min_turns)
