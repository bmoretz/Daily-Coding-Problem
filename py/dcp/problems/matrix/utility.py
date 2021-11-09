"""
some common matrix utilities.
"""

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