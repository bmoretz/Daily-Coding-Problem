'''Route Between Nodes.

Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
'''

'''
Graph 1:

A ---------> B
  \             \
    \ 
       C            \
    /     \
D --------> F ------> G
    \       |            \
       E    |             H
          \ |
            I
'''

graph = {
  'A' : ['B', 'C'],
  'B' : ['G'],
  'C' : ['F'],
  'D' : ['C', 'F', 'E'],
  'E' : ['I'],
  'F' : ['I'],
  'G' : ['H'],
  'H' : [],
  'I' : []
}


def has_route1(graph, node1, node2):

  def has_route(graph, node1, node2, visited = []):
    
    if node1 == node2:
      return True

    for neighbor in graph[node1]:

      if neighbor not in visited:
        visited.append(neighbor)

        if has_route(graph, neighbor, node2, visited): return True
    
    return False
  
  if graph == None: return None
  if node1 == None or node2 == None: return None

  if node1 not in graph.keys or node2 not in graph.keys: return False

  return has_route(graph, node1, node2)

ag_route = has_route1(graph, 'A', 'I')

print(ag_route)