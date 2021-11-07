class UnionFind:

    root = []

    def __init__(self, size : int) -> None:
        root = [0] * size

        for index in range(0, size):
            root[index] = index

        self.root = root

    def find(self, x : int) -> int:
        return self.root[x]

    def union(self, x, y) -> None:
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            for index in range(len(self.root)):
                if self.root[index] == root_y:
                    self.root[index] = root_x

    def connected(self, x, y) -> bool:
        return self.find(x) == self.find(y)


uf = UnionFind(10)

# 1-2-5-6-7 | 3-8-9-4
uf.union(1, 2)
uf.union(2, 5)
uf.union(5, 6)
uf.union(6, 7)

uf.union(3, 8)
uf.union(8, 9)


print(uf.connected(1, 5))
print(uf.connected(5, 7))
print(uf.connected(4, 9))

uf.union(9, 4)

print(uf.connected(4, 9))