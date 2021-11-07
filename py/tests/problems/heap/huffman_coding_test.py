import unittest

from dcp.problems.heap.huffman_tree import huffman_coding1

class Test_HuffmanCoding1(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):       
        value = 'aaacccccceeeeeeeeff'

        coded = huffman_coding1(value)

        assert coded['a'] == '101'
        assert coded['c'] == '11'
        assert coded['e'] == '0'
        assert coded['f'] == '100'
        
    def test_case2(self):
        pass