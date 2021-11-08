class UnionFind:
    """
    union find implementation that has a O(1)
    find operation, although union operations are O(N).
    """

    root = []

    def __init__(self, size : int) -> None:
        """
        initializes the structure with the
        specified size. Initially, all nodes
        are rooted at themselves (u[i] = i)

        Args:
            size (int): number of nodes
        """

        root = [0] * size

        for index in range(0, size):
            root[index] = index

        self.root = root

    def find(self, x : int) -> int:
        """
        find operation (returns parent), O(1)

        Args:
            x (int): [description]

        Returns:
            int: [description]
        """
        return self.root[x]

    def union(self, x, y) -> None:
        """
        1.) checks parents of x & y,
        2.) if != (not connected),
            then merge all of y's
            nodes into x's.

        Args:
            x ([type]): node 1
            y ([type]): node 2
        """
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            for index in range(len(self.root)):
                if self.root[index] == root_y:
                    self.root[index] = root_x

    def connected(self, x, y) -> bool:
        return self.find(x) == self.find(y)