class UnionFind:

    """
    union find implementation optimized with
    both path comppression and ranking (height 
    minimization)
    """

    root = []
    rank = []

    def __init__(self, size : int) -> None:
        """
        init: O(N)

        initially all nodes are rooted at
        themselves, with rank 1.

        Args:
            n (int): size of the graph
        """
        self.root = [idx for idx in range(size)]
        self.rank = [1] * size

    def find(self, x : int) -> int:
        
        """
        find w/ path compression, each
        time we search for a parent
        we save intermediate parents
        and compress the array, so
        each node points directly its
        parent.

        Returns:
            [type]: parent of x
        """

        if x == self.root[x]:
            return x

        self.root[x] = self.find(self.root[x])

        return self.root[x]

    def union(self, x : int, y : int) -> None:
        """
        union optimized with a rank operation
        to append to the smaller (in height) of 
        the two components.

        Args:
            x (int): node x
            y (int): noe y
        """
        root_x, root_y = self.find(x), self.find(y)

        if root_x != root_y:

            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = self.root[root_x]
            elif self.rank[root_y] > self.rank[root_x]:
                self.root[root_x] = self.root[root_y]
            else:
                self.root[root_y] = self.root[root_x]
                self.rank[root_x] = self.rank[root_x] + 1

    def connected(self, x : int, y : int) -> bool:
        return self.find(x) == self.find(y)