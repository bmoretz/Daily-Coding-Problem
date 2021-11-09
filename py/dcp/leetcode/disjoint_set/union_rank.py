class UnionFind:
    """
    union by rank implementation

    init: O(n)
    union/find/connected: O(log n)
    """

    root = []
    rank = []

    def __init__(self, size : int) -> None:
        """
        initializes the structure with the
        specified size. Initially, all nodes
        are rooted at themselves (u[i] = i),
        and ranked at 1.

        Args:
            size (int): number of nodes
        """        

        self.root = [idx for idx in range(size)]
        self.rank = [1] * size

    def find(self, x : int) -> int:
        """
        gets the parent of a node

        Args:
            x (int): node

        Returns:
            int: parent
        """

        while x != self.root[x]:
            x = self.root[x]

        return x

    def union(self, x : int, y : int):
        """
        find the parent nodes of each node,
        assign the new parent as the node
        with the lower rank.

        if equal, arbitrairly set parent
        as x and increment rank.

        Args:
            x (int): node x
            y (int): node y
        """
        root_x, root_y = self.find(x), self.find(y)

        if root_x != root_y:

            if self.rank[root_x] > self.rank[root_y]:
                self.root[root_y] = self.root[root_x]
            elif self.rank[root_x] < self.rank[root_y]:
                self.root[root_x] = self.root[root_y]
            else:
                self.root[root_y] = self.root[root_x]
                self.rank[root_x] = self.rank[root_x] + 1

    def connected(self, x, y) -> bool:

        return self.find(x) == self.find(y)