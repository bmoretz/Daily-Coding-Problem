''' Print the nth fibonacci number. '''

''' brute force. '''
def fib1(n):

    def fib(n):
        if n == 0: return 0
        if n == 1: return 1

        return fib(n - 2) + fib(n - 1)

    return fib(n)

''' dynamic. '''
def fib2(n):

    cache = {0: 0, 1: 1}

    def fib(n):
        if n not in cache:
            cache[n] = fib(n - 2) + fib(n - 1)
        
        return cache[n]
    
    return fib(n)