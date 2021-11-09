class UnionFind:
    """
    union find implementation that has O(n)
    union operation and a O(n) find operation.
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
        self.root = [idx for idx in range(size)]

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

    def union(self, x : int, y : int) -> None:
        """
        quick union:

            set the parent of x to the parent of y
            (if not already connected)

        Args:
            x (int): x
            y (int): y
        """
        root_x, root_y = self.find(x), self.find(y)

        if root_x != root_y:
            self.root[y] = self.root[root_x]
    
    def connected(self, x, y) -> bool:

        return self.find(x) == self.find(y)