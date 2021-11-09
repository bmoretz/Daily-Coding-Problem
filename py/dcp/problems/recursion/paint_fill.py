"""
Paint fill.

Implement the "paint fill" function that one might see on many image editing
programs. That is, given a screen (represented by a two-dimensional array of 
colors), a point, and a new color, fill in the surrounding area until the color
changes from the original color.

"""

from enum import Enum

class Color(Enum):
    BLACK = 0
    WHITE = 1
    RED = 2
    GREEN = 3
    BLUE = 4

def fill_rect(grid, point, col):
    
    def fill(grid, point, old_col, new_col):

        row, col = point

        n_row, n_col = len(grid) - 1, len(grid[0]) - 1

        if row < 0 or row > n_row: return False
        if col < 0 or col > n_col: return False
        
        old_col = grid[row][col]

        if grid[row][col] == old_col:

            grid[row][col] = new_col

            fill(grid, (row-1, col), old_col, new_col)
            fill(grid, (row+1, col), old_col, new_col)
            fill(grid, (row, col-1), old_col, new_col)
            fill(grid, (row, col+1), old_col, new_col)

        return True

    row, col = point
    
    n_row, n_col = len(grid) - 1, len(grid[0]) - 1

    if row < 0 or row > n_row: return False
    if col < 0 or col > n_col: return False
    
    old_col = grid[row][col]

    fill(grid, point, old_col, col)