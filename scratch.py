'''Check Balanced.

Implement a function to check if a binary tree is balanced.

For the purposes of this question, a balanced tree is defined to be a tree such
that the heights of the two subtrees of any node never differ by more than one.
'''

class TreeNode():

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_balanced(tree):

    def leaf_count(node, count=0):

        if node == None: return count

        level_count = 0

        if node.left:
            level_count += leaf_count(node.left, count)
            level_count += 1
        
        if node.right:
            level_count -= leaf_count(node.right, count)
            level_count -= 1

        return level_count

    return abs(leaf_count(tree)) <= 1

root = TreeNode(4)
root.left = TreeNode(3)
root.left.left = TreeNode(2)
root.left.left.left = TreeNode(1)

# root.right = right

balanced = is_balanced(root)

print(balanced)



