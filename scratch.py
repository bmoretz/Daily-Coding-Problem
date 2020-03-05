'''Rotate Matrix.

Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees.

Can you do it in place?
'''

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
    return list(zip(*mat[::-1]))


n, m = 5, 5

mat = build_mat(n, m)

print(mat)

print(rotate1(mat))
print(rotate2(mat))

