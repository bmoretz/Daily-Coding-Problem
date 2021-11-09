"""Rotate Matrix.

Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees.
"""

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