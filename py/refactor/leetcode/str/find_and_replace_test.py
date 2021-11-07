import unittest

from leetcode.str.find_and_replace import findReplaceString

class Test_FindAndReplace(unittest.TestCase):

    def test_case1(self):
        
        str_in = "jjievdtjfb"

        indexes, sources, targets = [4,6,1], ["md","tjgb","jf"], ["foe","oov","e"]

        actual = findReplaceString(str_in, indexes, sources, targets)

        expected = "jjievdtjfb"
        
        assert actual == expected