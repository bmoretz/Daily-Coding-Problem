
'''
498. Diagonal Traverse.

Given a matrix of M x N elements (M rows, N columns), return all 
elements of the matrix in diagonal order as shown in the below image. 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

Note:

The total number of elements of the given matrix will not exceed 10,000.
'''

class diagonal_traverse():
    
    from typing import List
    
    @staticmethod
    def findDiagonalOrder(matrix : List[List[int]]) -> List[int]:
        from collections import defaultdict, deque
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        if not matrix:
            return []
        
        num_rows, num_cols = len(matrix), len(matrix[0])
        ht = defaultdict(deque)
        
        for row in range(num_rows):
            for col in range(num_cols):
                s = row + col
                if s % 2:
                    ht[s].appendleft(matrix[row][col])
                else:
                    ht[s].append(matrix[row][col])
        
        index, result = 0, []
        
        while ht[index]:
            while ht[index]:
                result.append(ht[index].pop())
            index+=1
            
        return result