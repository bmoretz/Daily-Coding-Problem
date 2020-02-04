'''Maximum XOR.

Find the maximum XOR of element pairs.

Given an array of integers, find the maximum XOR of any two elements.
'''

ENDS_HERE = '#'

class MaxXOR:

    def __init__(self, values):
        self._trie = {}
        self.size = 0

        for val in values:
            self.size = max(self.size, val.bit_length())

        for val in values: self.insert(val)

    def insert(self, item):
        
        trie = self._trie

        for index in range(self.size, -1, -1):
            bit = bool(item & (1 << index))
            
            if bit not in trie:
                trie[bit] = {}
            
            trie = trie[bit]

    def find_max_xor(self, item):
        trie = self._trie
        xor = 0

        for index in range(self.size, -1, -1):
            bit = bool(item & (1 << index))

            if (1 - bit) in trie:
                xor |= (1 << index)
                trie = trie[1 - bit]
            else:
                trie = trie[bit]

        return xor

values = [4, 7, 6]
mx = MaxXOR(values)


print(mx.find_max_xor(2))