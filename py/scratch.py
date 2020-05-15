'''English Int.

Given an integer, print an English phrase that describes the integer (e.g., 
"One Thousand, Two Hundred Thirty-Four").
'''

digits = {
    1 : "One",
    2 : "Two",
    3 : "Three",
    4 : "Four",
    5 : "Five",
    6 : "Six",
    7 : "Seven",
    8 : "Eight",
    9 : "Nine",
}

special = {
    11 : "Eleven",
    12 : "Twelve",
    13 : "Thirteen",
}

suffix = {
    10 : "teen",
    20 : "twenty",
    30 : "thirty"
}

places = {
    1e0 : '',
    1e1 : 'Teen',
    1e2 : 'Hundred',
    1e3 : 'Thousand',
    1e6 : 'Million'
}

tens = {
    10 : "Ten",
    20 : "Twenty",
    30 : "Thirty",
    40 : "Forty",
    50 : "Fifty",
    60 : "Sixty",
    70 : "Seventy",
    80 : "Eighty",
    90 : "Ninety"
}

def english_int(num):

    from collections import defaultdict

    def separate_digits(number):
        from math import log, ceil, floor

        num_digits = ceil(log(num, 10))

        values = []

        for index in range(num_digits):

            position = pow(10, index)
            place = num % pow(10, index + 1)
            digit = floor(place / position)

            values += [(position, digit)]
        
        return values

    values = separate_digits(num)

    result = defaultdict(str)

    prior = (0, 0)

    for index in range(len(values)):
        current = values[index]

        position, digit = current

        compound = position + prior[1]

        if compound in special:

            result[position] = special[compound]
            result[prior[0]] = ''
            
        else:

            result[ position ] = places[ position ] + digits[ digit ]

        prior = current

    return ' '.join(result.values())


result = english_int(456)

print(result)
