
from collections import defaultdict

'''5.4

Implement a sparse matrix.

You have a large array, most of whose elements are zero.

Create a more space-efficient data structure, SparseArray, that implements the following interface:

+ init(mat, width, height): initialize with the original large array and size.

+ set(row, col, val): update index at [row, col] to be val.

+ get(i): get the value at index [row, col].

'''

mat = [[0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1], \
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1]]

rec_dd = lambda: defaultdict(rec_dd)

class SparseMatrix:

    def __init__(self, mat, width, height):
        self._values = rec_dd()
        self._size = (width, height)

        for n, row in enumerate(mat):
            for m, val in enumerate(row):
                if val != 0:
                    self._values[n][m] = val

    def _check_bounds(self, n, m):
        if n < 0 or n >= self._size[0] or m < 0 or m >= self._size[1]:
            raise IndexError('Out of bounds')

    def set(self, row, col, value):

        self._check_bounds(row, col)

        if value != 0:
            self._values[row][col] = value
            return
        elif col in self._values[row]:
            del self._values[row][col]

    def get(self, row, col):
        
        self._check_bounds(row, col)

        return self._values.get(row, []).get(col, 0)

sm = SparseMatrix(mat, 100, 100)

non_zero = [[5, 13, 19, 28], \
            [5, 13, 19, 28], \
            [5, 13, 19, 28], \
            [5, 13, 19, 28], \
            [5, 13, 19, 28]]

for n, row in enumerate(mat):
    for m, val in enumerate(row):

        if m in non_zero[n]:
            assert sm.get(n, m) != 0
        else:
            assert sm.get(n, m) == 0
