'''Kth Multiple.

Design an algorithm to find the kth number such that the only prime
factors are 3, 5, and 7. Note that 3, 5 and 7 do not have to be
factors, but it should not have any other prime factors. For
example, the first several multiples would be (in order)
1, 3, 5, 7, 9, 15, 21.
'''

'''brute force O(k^3)'''
def kth_smallest1(k):

    def all_possible(k):
        solutions = []

        for a in range(k):
            for b in range(k):
                for c in range(k):
                    n = 3**a * 5**b * 7**c
                    solutions += [n]
        
        return solutions

    if k < 0: return 0

    possible = all_possible(k)

    possible = sorted(possible)

    return possible[k - 1]

'''O(K) solution'''
def kth_smallest2(k):
    
    from collections import deque

    def front_or_default(queue):
        return queue[0] if len(queue) > 0 else float('inf')

    if k < 0: return 0
    
    val = 0

    q3, q5, q7 = deque(), deque(), deque()
    
    q3.append(1)

    for index in range(k):

        v3 = front_or_default(q3)
        v5 = front_or_default(q5)
        v7 = front_or_default(q7)

        val = min(v3, min(v5, v7))

        if val == v3:
            q3.popleft()
            q3.append(3 * val)
            q5.append(5 * val)
        elif val == v5:
            q5.popleft()
            q5.append(5 * val)
        elif val == v7:
            q7.popleft()

        q7.append(7 * val)

    return val

k = 48

print(kth_smallest1(k))
print(kth_smallest2(k))