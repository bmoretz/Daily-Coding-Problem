
''' Paint houses.

A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while 
ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, 
return the minimum cost which achieves this goal.
'''

''' O(n*k*k) solution. '''
def paint_houses1(matrix):

    n = len(matrix)
    k = len(matrix[0])
    solution_matrix = [[0] * k]

    # Solution matrix: matrix[i][j] represents the minimum cost to build house i with color j.
    # build house i with color j.
    for r, row in enumerate(matrix):
        row_cost = []
        for c, val in enumerate(row):
            row_cost.append(min(solution_matrix[r][i]
                            for i in range(k)
                            if i != c) + val)
        solution_matrix.append(row_cost)

    return min(solution_matrix[-1])