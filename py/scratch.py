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

def pond_size(mat):
    
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

mat =[[0, 2, 1, 0, 0, 0],
                [0, 1, 0, 1, 0, 1],
                [1, 1, 0, 1, 0, 1],
                [0, 1, 0, 1, 1, 1],
                [0, 1, 0, 1, 1, 1]]



result = pond_size(mat)

print(result)