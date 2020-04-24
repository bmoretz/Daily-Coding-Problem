'''Coins.

Given an infinite number of quarters (25 cents), 10 dimes (10 cents),
nickels (5 cents), and pennies (1 cent), write code to calculate the number
of ways of representing n cents.
'''

def coin_ways1(n):

    seen_ways = {}

    def coin_ways(n):
        if n <= 0: return 0

        if n in seen_ways: return seen_ways[n]

        total = 0

        for denom in (25, 10, 5, 1):
            
            if denom <= n:

                cur = n - denom
                total += 1

                if cur in seen_ways:
                    total += seen_ways[cur]
                else:
                    total += coin_ways(cur)

        seen_ways[n] = total

        return total

    if n == None: return None

    return coin_ways(n)

ways = coin_ways1(100)

print(ways)