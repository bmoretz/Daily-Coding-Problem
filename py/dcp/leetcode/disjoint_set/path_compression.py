class UnionFind:

    root = []

    def __init__(self, size : int) -> None:
        
        self.root = [idx for idx in range(size)]

    def find(self, x : int) -> int:
        
        if x == self.root[x]:
            return x
        
        self.root[x] = self.find(self.root[x])

        return self.root[x]

    def union(self, x : int, y : int) -> None:
        
        root_x, root_y = self.find(x), self.find(y)
        
        if root_x != root_y:
            self.root[root_y] = self.root[root_x]

    def connected(self, x : int, y : int) -> bool:
        return self.find(x) == self.find(y)