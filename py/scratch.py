'''Tic Tac Win.

Design an algorithm to figure out if someone has won a game of tic-tak-toe.
'''

def make_board(n=3):
    return [[None for c in range(n)] for r in range(n)]

def check_win(board):

    def get_pos_value(piece):
        return -1 if piece == 'X' else 1

    def check_cols(board):
        
        n, m = len(board), len(board[0])

        for col in range(m):
            total = 0
            for row in range(n):
                total += get_pos_value( board[row][col] )

            if abs(total) == 3: return True
        
        return False

    def check_rows(board):

        n, m = len(board), len(board[0])

        for row in range(n):
            total = 0
            for col in range(m):
                total += get_pos_value( board[row][col] )

            if abs(total) == 3: return True
        
        return False

    def check_diags(board):
        
        n, m = len(board), len(board[0])

        total, position = 0, 0
        for _ in range(n):
            total += get_pos_value( board[position][position] )
            position += 1
        
        if abs(total) == 3: return True

        total, position = 0, 2
        for row in range(n):
            total += get_pos_value( board[position][position] )
            position -= 1
        
        if abs(total) == 3: return True

        return False        

    if board == None: return None

    if check_diags(board): return True
    if check_rows(board): return True
    if check_cols(board): return True
    
    return False

board = make_board()
board[0] = ['O', 'X', 'O']
board[1] = ['X', 'O', 'X']
board[2] = ['O', 'X', 'O']

win = check_win(board)

print(win)
