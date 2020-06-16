'''Count of 2's.

Write a method to count the number of 2's that appear in all the 
numbers between 0 and n (inclusive).

EXAMPLE:
Input: 25
Output: 9 (2, 12, 20, 21, 22, 23, 24 and 25. Note that 22 counts for two 2's)
'''

def count_twos1(n):
    from math import floor

    def num_twos(n):
        count = 0

        while n > 0:
            if n % 10 == 2:
                count += 1
            n = floor(n / 10)
        
        return count

    total = 0

    for index in range(n + 1):
        total += num_twos(index)
    
    return total

def count_twos2(n):
    from math import floor

    def twos_in_range(number, d) -> int:
        powers = pow(10, d)
        next_power = powers * 10
        right = number % powers

        round_down = number - number % next_power
        round_up = round_down + next_power

        digit = floor((number / powers) % 10)

        ans = 0

        if digit < 2:
            ans = round_down / 10
        elif  digit == 2:
            ans = round_down / 10 + right + 1
        else:
            ans = round_up / 10

        return floor(ans)

    count = 0
    length = len(str(n))

    for digit in range(length):
        count += twos_in_range(n, digit)

    return count

number = None

res = count_twos1(number)
print(res)
res = count_twos2(number)
print(res)
