'''Find floor and ceiling.

Given a binary search tree, find the floor and ceiling of a given integer. The floor is the hightest 
element in the tree less than or equal to an integer, while the ceiling is the lowest element in the 
tree greater than or equal to an integer.

If either value does not exist, return None.

'''

def floor_ceiling1(root, k):

    def get_bounds(root, x, floor=None, ceil=None):

        if not root:
            return floor, ceil

        if x == root.data:
            return x, x

        elif x < root.data:
            floor, ceil = get_bounds(root.left, x, floor, root.data)

        elif x > root.data:
            floor, ceil = get_bounds(root.right, x, root.data, ceil)

        return floor, ceil
    
    return get_bounds(root, k, k)