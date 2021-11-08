''' some common matrix utilities. '''

def print_mat(mat, col_width=2):

    if mat is None: return None

    rows = len(mat)

    for row in range(rows):
        print(''.join(str(element).ljust(col_width) for element in mat[row]))

def build_mat(n, m):
    if not isinstance(n, int) or not isinstance(m, int):
        raise TypeError('n and m must be integers')
    if n <= 0 or m <= 0:
        raise ValueError('n and m must be greater than zero')

    mat = [[None] * m for _ in range(n)]

    for row in range(n):
        for column in range(m):
            mat[row][column] = (row * m) + column + 1
    return mat

'''Rotate Matrix.

Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees.
'''

def rotate1(mat):
    
    if mat is None: return None

    rows = len(mat)
    cols = len(mat[0])

    ret = [[None] * cols for _ in range(rows)]

    for row in range(rows):

        for index, value in enumerate(mat[row]):
            ret[index][cols - row - 1] = value

    return ret

def rotate2(mat):

    if mat == None: return None

    return list(zip(*mat[::-1]))

'''Zero Matrix.

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to zero.
'''

''' O(M * N) run-time / O(N) space solution '''

def zero1(mat):

    def zero_column(mat, col):
        for row in range(len(mat)):
            mat[row][col] = 0
    
    def zero_row(mat, row):
        for col in range(len(mat[0])):
            mat[row][col] = 0
        
    if mat is None: return None

    rows = len(mat)
    cols = len(mat[0])

    zeros = []
    
    for row in range(rows):
        for column in range(cols):
            if mat[row][column] == 0:

                zeros += [(row, column)]

    for val in zeros:
        zero_row(mat, val[0])
        zero_column(mat, val[1])

    return mat

'''Pond Sizes.

You have an integer matrix representing a plot of land, where the
value at that location represents the height above sea level. A 
value of zero indicates water. A pond is a region of water connected
vertically, horizontally, or diagonally. The size of the pond is the 
total number of connected water cells. Write a method to compute the
sizes of all ponds in the matrix.

EXAMPLE:
Input:
    0   2   1   0
    0   1   0   1
    1   1   0   1
    0   1   0   1

Output: 2, 4, 1 (in any order)
'''

def pond_sizes(mat):
    
    def get_size(mat, row, col):
        
        n, m = len(mat) - 1, len(mat[0]) - 1

        if row < 0 or col < 0 \
            or row > n or col > m or \
            mat[row][col] != 0: return 0

        size = 1

        mat[row][col] = -1

        for dr in range(-1, 2):
            for dc in range(-1, 2):
                size += get_size(mat, row + dr, col + dc)

        return size

    if not mat: return None

    ponds = []

    for row in range(len(mat)):
        for col in range(len(mat[0])):

            if mat[row][col] == 0:
                ponds += [get_size(mat, row, col)]

    return ponds

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