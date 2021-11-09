'''Power Set.

Write a method to return all subsets of a set.
'''

def power_sets1(data):
    
    def subsets(seq):
        if len(seq) <= 1:
            yield seq
            yield []
        else:
            for item in subsets(seq[1:]):
                yield [seq[0]] + item
                yield item

    return list(subsets(data))