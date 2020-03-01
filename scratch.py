from collections import defaultdict

''' N Queens.

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
'''

def n_queens(n, board=[]):

    if n == len(board):
        return 1

    count = 0

    for col in range(n):
        board.append(col)

        if is_valid(board):
            count += n_queens(n, board)
        board.pop()

    return count

def is_valid(board):
    current_queen_row, current_queen_col = len(board) - 1, board[-1]

    # Check if any queens can attack the last queen.
    for row, col in enumerate(board[:-1]):

        diff = abs(current_queen_col - col)

        if diff == 0 or diff == current_queen_row - row:
            return False
    
    return True

nq = n_queens(8)

print(nq)
