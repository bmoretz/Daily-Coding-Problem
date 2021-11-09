def countComponents4(n: int, edges: list[list[int]]) -> int:

    connections = [idx for idx in range(n)]
    rank = [1] * n

    def get_parent(node : int) -> int:

        if node == connections[node]:
            return node

        connections[node] = get_parent(connections[node])

        return connections[node]

    def connect(u, v) -> None:

        pu, pv = get_parent(u), get_parent(v)

        if pu != pv:

            if rank[pu] > rank[pv]:
                connections[pv] = pu
            elif rank[pu] < rank[pv]:
                connections[pu] = pv
            else:
                connections[pv] = pu
                rank[pv] = rank[pv] + 1

    for edge in edges:
        u, v = edge[0], edge[1]
        connect(u, v)

    components = set()

    for node in range(n):
        components.add(get_parent(node))

    return len(components)


n, edges = 7, [[0,1], [1,2], [1,3], [4,5], [4,6], [1,5]]

actual = countComponents4(n, edges)
expected = 1