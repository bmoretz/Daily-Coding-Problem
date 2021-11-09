"""
Operations.

Write methods to implement the multiply, subtract and divide operations for
integers. The results of all these are integers. Use only the add operator.
"""

class Ops():

    @staticmethod
    def mult(a, b):
        
        result = 0

        for i in range(b):
            result += a

        return result

    @staticmethod
    def sub(a, b):
        return a + -b

    @staticmethod
    def div(a, b):

        result = 0

        while a >= b:

            a = a + -b
            result += 1

        return result