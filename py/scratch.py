'''Power Set.

Write a method to return all subsets of a set.
'''

def power_sets1(data):
    
    def subsets(data, index):
        
        n = len(data) - 1
        all_subsets = []

        if n == index:
            all_subsets += [None]
        else:
            all_subsets = subsets(data, index + 1)

            item = data[index]
            
            sub = []

            for ss in all_subsets:
                new = []
                new += ss
                new.append(item)
                sub.append(new)
                
        return all_subsets

    return subsets(data, 0)


items = ['a', 'b', 'c']

ps = power_sets1(items)

print(ps)

