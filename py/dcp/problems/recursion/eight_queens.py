'''Eight Queens.

Write an algorithm to print all ways of arranging eight queens on an 8x8 chess
board so that none of them share the same row, column, or diagonal. In this case,
"diagonal" means all diagonals, not just the two that bisect the board.
'''

def get_board(n):
    return [[0 for col in range(n)] for row in range(n)]
 
def place_queens(board):

    def try_place(board, row, col):

        colsum = 0
        
        for r in range(n_row):
            colsum += board[r][col]

        rowsum = sum(board[row])

        diagsum = 0

        if row < n_row - 1:
            if col < n_col - 1:
               diagsum += board[row + 1][col + 1]
            if col > 0:
                diagsum += board[row + 1][col - 1]

        if colsum == 0 and rowsum == 0 and diagsum == 0:
            board[row][col] = 1

        return board[row][col]

    if board == None: return None

    n_row, n_col = len(board), len(board[0])

    placed = 0

    for row in range(n_row)[::-1]:

        for col in range(n_col)[::-1]:

           if try_place(board, row, col):
               placed += 1
               break


    return board if placed == n_col else None