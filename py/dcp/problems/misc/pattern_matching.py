"""
Pattern Matching.

You are given two strings, pattern and value. The pattern string consists of
just the letters a and b, describing a pattern within a string. For example,
the string catcatgocatgo matches the pattern aabab (where cat is a and go
is b). It also matches patterns like a, ab, and b. Write a method to
determine if value matches pattern.
"""

def pattern_match1(value, pattern):

    def is_valid_pattern(pattern):
        
        n = len(pattern)

        if n == 0: return False

        for index in range(1, n):
            if not pattern[index] == pattern[index - 1]:
                return False

        return True

    def extract_pattern(value, pattern, a_len, b_len):
        
        a_values, b_values = [], []

        index = 0
        n, np = len(value), len(pattern)

        position = 0

        while True:
            
            current = pattern[position]

            if current == 'a':    
                a_values += [value[index:index + a_len]]
                index += a_len
            else:
                b_values += [value[index:index + b_len]]
                index += b_len

            position += 1

            if index >= n or position >= np:
                break
        
        return a_values, b_values

    if value == None or pattern == None: return None
    
    n = len(value)

    num_a, num_b = 0, 0

    for c in pattern:
        if c == 'a':
            num_a += 1
        else:
            num_b += 1

    for len_a in range(1, n):
        for len_b in range(1, n):
            
            a, b = extract_pattern(value, pattern, len_a, len_b)

            if is_valid_pattern(a) and is_valid_pattern(b):
                return len(a) == num_a and len(b) == num_b

    return False