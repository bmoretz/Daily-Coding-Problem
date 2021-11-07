'''Implement a sparse matrix.

You have a large n by m array of data, most of whose elements are zero.

Create a more space-efficient data structure, SparseMatrix, that implements the following interface:

+ init(mat, width, height): initialize with the original large n by m array and size.

+ set(row, col, val): update index at [row, col] to be val.

+ get(row, col): get the value at index [row, col].

'''

from collections import defaultdict

rec_dd = lambda: defaultdict(rec_dd) # recursive defaultdict for sparse matrix

class SparseMatrix:
    '''O(n * m) initialize'''
    def __init__(self, mat, width, height):
        self._values = rec_dd()
        self._n, self._m = width, height

        for n, row in enumerate(mat):
            for m, val in enumerate(row):
                if val != 0:
                    self._values[n][m] = val

    '''O(1) check bounds'''
    def _check_bounds(self, n, m):
        if n < 0 or n >= self._n or m < 0 or m >= self._m:
            raise IndexError('Out of bounds')

    '''O(1) set val'''
    def set(self, row, col, value):

        self._check_bounds(row, col)

        if value != 0:
            self._values[row][col] = value
            return
        elif col in self._values[row]:
            del self._values[row][col]

    '''O(1) get val'''
    def get(self, row, col):
        
        self._check_bounds(row, col)

        return self._values.get(row, []).get(col, 0)
