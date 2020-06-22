'''Baby Names.

Each year, the government releases a list of the 10,000 most common baby names and
their frequencies (the number of babies with that name). The only problem with this is
that some names have multiple spellings. For example, "John" and "Jon" are essentially
the same name but would be listed seperately in the list. Given two lists, one of names/
frequencies and the other of pairs of equivalent names, write an algorithm to print a new
list of the true frequencies of each name. Note that if John and Jon are synonyms, and
Jon and Johnny are synonyms, then John and Johnny are synonyms. (It is both transitive
and symmetric.) In the final list, any name can be used as the "real" name.

EXAMPLE

Input:
    Names: John (15), Jon (12), Chris (13), Christopher (19)
    Synonyms: (John, Jon), (John, Johnny), (Chris, Kris), (Chris, Christopher)
Output:
    John (27), Kris (36)
'''

class BabyNames():

    from collections import defaultdict
    
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

names = [('John', 15), ('Jon', 12), ('Chris', 13), ('Kris', 4), ('Christopher', 19)]
synonyms = [('John', 'Jon'), ('John', 'Johnny'), ('Chris', 'Kris'), ('Chris', 'Christopher')]

bn = BabyNames()

for name, count in names:
    bn.add_name(name, count)

for a, b in synonyms:
    bn.add_synonym(a, b)

result = bn.get_unique()

print(result)