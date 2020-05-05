'''Rank from Stream.

Imagine you are reading in a stream of integers. Periodically, you wish to be
able to look up the rank of a number x (the number of values less than or equal
to x). Implement the data structures and algorithms to support these operations.
That is, implement the method track (int x), which is called when each number is
generated, and the method getRankOfNumber (int x), which returns the number of
values less than or equal to x (not including x itself).

EXAMPLE:

Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3

getRankOfNumber(1) = 0
getRankOfNumber(3) = 1
getRankOfNumber(4) = 3
'''

class RankStream():

    def __init__(self):
        self.root = None

    class Node():
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.left = left
            self.right = right

    def track(self, data):

        if self.root == None:
            self.root = self.Node(data)
        else:
            
            node, prev = self.root, None

            while node != None:
                
                prev = node

                if data <= node.data and node.right != None:
                    node = node.left
                else:
                    node = node.right
            
            node = prev

            if node.left == None:
                node.left = self.Node(data)

                if node.data < data:
                    node.data, node.left.data = node.left.data, node.data

            else:
                node.right = self.Node(data)

                if node.data > data:
                    node.data, node.right.data = node.right.data, node.data
            
    def get_rank(self, num):

        def count_children(parent, value):

            if parent == None:
                return 0

            result = 1 if parent.data <= value else 0

            if value < parent.data:
                return result + count_children(parent.left, value)
            else:
                return result + count_children(parent.left, value) \
                    + count_children(parent.right, value)

        if num == None: return None

        return count_children(self.root, num)

values = [5, 1, 4, 4, 5, 9, 7, 13, 3]

rs = RankStream()

for value in values:

    rs.track(value)

results = rs.get_rank(13)

print(results)