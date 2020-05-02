'''Sorted Search, No Size.

You are given an array-like data structure Listy, which lacks a size method. It does,
however, have an elementAt(i) method that returns the element at index i in O(1) time. If
i is beyond the bounds of the data structure, it returns -1. (For this reason, the 
data structure only supports positive integers). Given a Listy which contains sorted,
positive integers, find the index at which an element x occurs multiple times, you
may return any index.
'''

class Listy():

    def __init__(self, values):
        assert [x >= 0 for x in values]
        self.data_ = list(sorted(values))

    def element_at(self, index):

        if index < 0 or index >= len(self.data_): 
            return -1
        else:
            return self.data_[index]

def sorted_find(lst, element):

    def get_length(lst):

        power = 0

        while lst.element_at( 2**power ) != -1:
            power += 1

        if power == 0: return 0

        lower = 2**(power-1)

        for index in range(power, -1, -1):
            j = 2**index

            if lst.element_at(lower + j) != -1:
                lower += j 

        return lower + 1
        
    def find(lst, element, start, stop):
        
        if start > stop: return -1

        mid = start + (stop - start)//2

        cur = lst.element_at( mid )

        if cur == element:
            return mid
        elif element < element:
            return find(lst, element, start, mid - 1)
        else:
            return find(lst, element, mid + 1, stop) 

    if lst == None: return None

    n = get_length(lst) - 1

    return find(lst, element, 0, n - 1)

values = [1, 1, 1, 1, 2, 3, 10, 12, 15]
values = [0] * 128 + [1, 1, 1, 1, 2, 3, 10, 12, 15]

lst = Listy(values)    

result = sorted_find(lst, 10)

print(result)