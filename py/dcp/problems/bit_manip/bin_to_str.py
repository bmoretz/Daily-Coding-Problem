'''Binary to String.

Given a real number between 0 and 1 (e.g., .72) that is passed in as
a double, print the binary representation. If the number cannot be
represented accurately in binary with at most 32 characters, print "ERROR".
'''

def binrep1(num, tol=0.00001):
    
    if num >= 1 or num <= 0: return 'ERROR'

    result, frac = '.', 0.5
    
    while num > tol:
        if len(result) >= 32:
            return 'ERROR'

        if num >= frac:
            result += '1'
            num -= frac
        else:
            result += '0'
        
        frac /= 2

    return result