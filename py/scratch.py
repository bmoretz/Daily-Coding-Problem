'''English Int.

Given an integer, print an English phrase that describes the integer (e.g., 
"One Thousand, Two Hundred Thirty-Four").
'''

digits = {
    0 : "",
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
    0 : '',
    1e0 : '',
    1e1 : 'Teen',
    1e2 : 'Hundred',
    1e3 : 'Thousand',
    1e4 : 'Ten Thousand',
    1e6 : 'Million'
}

tens = {
    0 : "",
    1 : "Ten",
    2 : "Twenty",
    3 : "Thirty",
    4 : "Forty",
    5 : "Fifty",
    6 : "Sixty",
    7 : "Seventy",
    8 : "Eighty",
    9 : "Ninety"
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
        
    if num == None: return None
    if num == 0: return 'Zero'

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

        elif position == 10:

            p = tens[ digit ]

            result[ position ] = p
        else:
            
            p = places[ position ]
            d = digits[ digit ]
            
            result[ position ] = d + ' ' + p

        prior = current

    eng = ''

    for value in sorted(result.keys(), key=lambda x:-x):
        eng += result[value] + ' '

    return eng.strip()


# 456
result = english_int(2300)

print(result)
