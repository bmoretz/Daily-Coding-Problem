'''Zero Matrix.

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to zero.
'''

m, n = 4, 4

mat = [[1] * n for _ in range(m)]

mat[0][1] = 0
mat[1][2] = 0
mat[3][0] = 0

def print_mat(mat, col_width=2):

    if mat is None: return None

    rows = len(mat)

    for row in range(rows):
        print(''.join(str(element).ljust(col_width) for element in mat[row]))

def zero_mat1(mat):

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

print_mat(mat)

zero_mat = zero_mat1(mat)
print_mat(zero_mat)
print(zero_mat)