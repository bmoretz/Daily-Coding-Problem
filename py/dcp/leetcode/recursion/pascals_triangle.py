
'''
118. Pascal's Triangle.

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
'''

def generate(num_rows: int) -> list[list[int]]:
    
    triangle = []
    
    for row_num in range(num_rows):
        
        row = [None] * (row_num+1)
        row[0], row[-1] = 1, 1
        
        for col in range(1, len(row)-1):
            row[col] = triangle[row_num-1][col-1] + triangle[row_num-1][col]
        triangle.append(row)

    return triangle

