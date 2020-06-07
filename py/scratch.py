'''Calculator.

Given an arithemetic equation consisting of positive integers, +, -,
*, and / (no parenthesis), compute the result.

EXAMPLE:

Input: 2*3+5/6*3+15
Output: 23.5
'''

def calculate1(expr):
    
    def tokenize(expr):
        ops = {
            '+' : [ lambda x, y: x + y ],
            '-' : [ lambda x, y: x - y ],
            '*' : [ lambda x, y: x * y ],
            '/' : [ lambda x, y: x / y ]
        }

        tokens, cur = [], ''
        
        mults, adds = 0, 0

        for c in expr:
            if c in ops:
                tokens += [int(cur)]
                tokens += [(c, ops[c])]

                if c in ['+', '-']:
                    adds += 1
                else:
                    mults += 1
                
                cur = ''
            else:
                cur += c
        
        tokens += [int(cur)]

        return (tokens, mults, adds)

    def process(tokens, op_type):

        for index, token in enumerate(tokens):

            if type(token) == tuple:
                if token[0] in op_type:
                    func, x, y = token[1][0], \
                        tokens[index - 1], tokens[index + 1]

                    left = tokens[:index - 1]
                    result = [func(x, y)]
                    right = tokens[index + 2:]

                    return left + result + right

        return tokens

    if not expr: return None

    tokens, mults, adds = tokenize(expr)

    for _ in range(mults):
        tokens = process(tokens, '*/')
    
    for _ in range(adds):
        tokens = process(tokens, '+-')

    return tokens[0]

expr = "1+2+3+4+5/5"

res = calculate1(expr)

print(res)