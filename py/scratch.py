'''Langton's Ant

An ant is sitting on an infinite grid of white and black squares. It 
initially faces right. At each step, it does the following:

1.) At a white square, flip the color of the square, turn 90 degrees
right (clockwise), and move forward one unit.

2.) At a black square, flip the color of the square, turn 90 degrees
left (counter-clockwise), and move forward one unit.

Write a program to simulate the first K moves that the ant makes and
print the final board as a grid. Note that you are not provided with
the data structure to represent the grid. This is something you must
design yourself. The only input to your method is K. You should print
the final grid and return nothing. The method signature might be
something like 'void printKMoves(int K).
'''

def printKMoves(K):
    
    def build_board(K):
        board = []

        for row in range(K):
            prev = 'W' if row % 2 == 0 else 'B'
            cur = []
            for col in range(K):
                cur += [prev]
                prev = 'B' if prev == 'W' else 'W'

            board += [cur]

        return board

    board = build_board(2*K)

    r, c = K//2, K//2
    direction = 90

    for m in range(K):

        if board[r][c] == 'W':
            board[r][c] = 'B'
            direction += 90
        else:
            board[r][c] = 'B'
            direction -= 90

        if direction == 0:
            r -= 1
        elif direction == 90:
            c += 1
        elif direction == 180:
            r += 1
        elif direction == 270:
            c -= 1

    return board


b = printKMoves(5)

for row in b:
    line = ''
    for c in row:
        line += f'{c} '
    print(line)

            

