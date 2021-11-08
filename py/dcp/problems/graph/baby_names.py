from collections import defaultdict

class BabyNames():
    
    class Node():

        def __init__(self, name, count):
            self.name = name
            self.count = count
            self.edges = []

        def add_edge(self, other):
            self.edges += [other]

        def __hash__(self):
            return hash(self.name) + self.count

    def __init__(self):
        self.names = defaultdict(self.Node)
        
    def add_name(self, name, count=0):
        self.names[name] = self.Node(name, count)

    def add_synonym(self, primary, secondary):

        if primary not in self.names:
            self.add_name(primary)
        
        if secondary not in self.names:
            self.add_name(secondary)

        a, b = self.names[primary], self.names[secondary]

        a.add_edge( b )
        b.add_edge( a )

    def get_unique(self):

        totals = defaultdict(int)
        seen = set()

        for name in self.names:

            to_visit = [self.names[name]]

            while to_visit:
                
                node = to_visit.pop()

                if node in seen:
                    continue

                for neighbor in node.edges:
                    to_visit += [neighbor]

                totals[name] += node.count
                seen.add(node)

        return totals