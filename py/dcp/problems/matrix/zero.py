"""Zero Matrix.

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to zero.
"""

def zero1(mat):
    """
    O(M * N) run-time / O(N) space solution 
    
    Args:
        mat ([type]): [description]
    """

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
