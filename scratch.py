'''Running Median

Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far after each new element.

For example, giveen the sequence [2, 1, 5, 7, 2, 0, 5],

Your algorithm should print out:

2
1.5
2
3.5
2
2
2
'''

class RunningMedian1():

    def __init__(self):
        self._values = []

    def median(self):
        if not self._values: return None
        
        n = len(self._values)
        ind = int(n / 2)

        return self._values[ind] if n % 2 == 1 else sum(self._values[ind-1:ind+1]) / 2

    def insert(self, value):

        self._values.append(value)
        self._values = sorted(self._values)

values = [2, 1, 5, 7, 2, 0, 5]

rm = RunningMedian1()

for val in values:
    rm.insert(val)
    print(rm.median())
