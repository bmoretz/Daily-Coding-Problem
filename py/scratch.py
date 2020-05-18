'''Operations.

Write methods to implement the multiply, subtract and divide operations for integers. The
results of all these are integers. Use only the add operator.
'''


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

        while a > b:

            a = a + -b
            result += 1

        return result


a, b = 9, 2

print(f'{a}/{b} = ', Ops.div(a, b))
print(f'{a}-{b} = ', Ops.sub(a, b))
print(f'{a}*{b} = ', Ops.mult(a, b))