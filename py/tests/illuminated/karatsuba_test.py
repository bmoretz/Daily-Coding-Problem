import unittest

from problems.illuminated import karatsuba

class Test_Karatsuba(unittest.TestCase):
    
    def setUp(self):
        pass

    def test_case1(self):

        x, y = 45, 76

        actual = karatsuba(x, y)
        expected = 3420

        assert actual == expected

    def test_case2(self):

        x, y = 4898, 3988

        actual = karatsuba(x, y)
        expected = 19533224

        assert actual == expected

    def test_case3(self):

        x, y = 1465, 1275

        actual = karatsuba(x, y)
        expected = 1867875

        assert actual == expected

    def test_case4(self):

        x, y = 146, 127

        actual = karatsuba(x, y)

        expected = 18542

        assert actual == expected

    def test_case5(self):

        x = 3141592653589793238462643383279502884197169399375105820974944592
        y = 2718281828459045235360287471352662497757247093699959574966967627

        actual = karatsuba(x, y)

        expected = 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184

        assert actual == expected