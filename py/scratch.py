'''Robot in a Grid.

Imagine a robot sitting on the upper left corner of grid with r rows and c columns.

The robot can only move in two directions, right and down, but certain cells are "off limits" such
that the robot cannot step on them. Design an algorithm to find a path for the robot from the top
left to the bottom right.
'''

def build_grid(rows, columns, obsticals):

    grid = [[0 for x in range(rows)] for x in range(columns)] 

    for coord in obsticals:
        grid[coord[0]][coord[1]] = 1

    return grid


obsticals = [(0, 4), (1,1), (0,4), (1,4), (2, 0), (2,2), (2, 4), (3, 2), (3, 4), (4,2)]
grid = build_grid(6, 5, obsticals)

def walk(grid, path=None):

    def step(path, x, y):
        return path + [(x, y)]

    if path == None:
        path = [(0, 0)]

    x, y = path[-1][0], path[-1][1]

    rows, columns = len(grid), len(grid[0])

    if x == rows - 1 and y == columns - 1:
        return path

    walk_right = y < columns - 1 and grid[x][y+1] == 0

    if walk_right:
        path = walk(grid, step(path, x, y + 1))

        if path[-1] == (rows - 1, columns - 1):
            return path

    walk_down = x < rows - 1 and grid[x+1][y] == 0

    if walk_down:
        path = walk(grid, step(path, x + 1, y))

        if path[-1] == (rows - 1, columns - 1):
            return path
    
    if not (walk_right or walk_down):
        path = step(path, -1, -1) # stuck

    return path

path = walk(grid)