
"""
323. Number of Connected Components in an Undirected Graph

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that 
there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

Example 1:

Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

Example 2:

Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

Constraints:

    1 <= n <= 2000
    1 <= edges.length <= 5000

    edges[i].length == 2

    0 <= ai <= bi < n
    ai != bi

There are no repeated edges.

"""

def countComponents1(n: int, edges: list[list[int]]) -> int:
    """
    quick find based implemenation

    Args:
        n (int): number of nodes
        edges (list[list[int]]): list of edges

    Returns:
        int: number of connected components
    """
    connections = [n for n in range(n)]

    for edge in edges:
        left, right = edge[0], edge[1]

        if connections[left] != connections[right]:

            old_group = connections[right]
            connections[right] = connections[left]

            for index in range(n):
                if connections[index] == old_group:
                    connections[index] = connections[left]

    return len(set(connections))

def countComponents2(n: int, edges: list[list[int]]) -> int:
    """
    quick union based implementation

    Args:
        n (int): number of nodes
        edges (list[list[int]]): list of edges

    Returns:
        int: number of connected components
    """
    connections = [n for n in range(n)]

    def get_parent(node):

        while node != connections[node]:
            node = connections[node]
        
        return node

    for edge in edges:
        u, v = get_parent(edge[0]), get_parent(edge[1])

        connections[u] = connections[v]
        
    components = set([get_parent(n) for n in range(n)])

    return len(components)

def countComponents3(n: int, edges: list[list[int]]) -> int:
    """
    union by rank based implementation

    Args:
        n (int): [description]
        edges (list[list[int]]): [description]

    Returns:
        int: number of connected components
    """
    connections = [idx for idx in range(n)]
    rank = [1] * n

    def get_group(node : int):

        while node != connections[node]:
            node = connections[node]

        return node

    def connect(u, v) -> None:
        
        gu, gv = get_group(u), get_group(v)

        if gu != gv:

            if rank[gu] > rank[gv]:
                connections[gv] = gu
            elif rank[gv] > rank[gu]:
                connections[gv] = gu
            else:
                connections[gv] = gu
                rank[v] = rank[v] + 1

    for edge in edges:
        u, v = edge[0], edge[1]
        connect(u, v)

    components = set()

    for node in range(n):
        components.add(get_group(node))

    return len(components)

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