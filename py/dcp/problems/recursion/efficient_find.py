"""
Find array extremes efficiently.

Given an array of numbers of length n,, find both the minimum and maximum using less than 2 * (n -2) comparisons.
"""

def min_and_max1(arr):
    """
    straight forward enumeration
    
    Args:
        arr ([type]): [description]

    Returns:
        [type]: [description]
    """
    min_element = max_element  = arr[0]

    compare = lambda x, y: (x, y) if y > x else (y, x)

    # Make the list odd so we can pair up the remaining elements neatly.
    if len(arr) % 2 == 0:
        arr.append(arr[-1])

    for i in range(1, len(arr), 2):
        smaller, bigger = compare(arr[i], arr[i + 1])
        min_element = min(min_element, smaller)
        max_element = max(max_element, bigger)

    return min_element, max_element

def min_and_max2(arr):
    """
    divide & conquer approach

    Args:
        arr ([type]): [description]

    Returns:
        [type]: [description]
    """
    if len(arr) == 1:
        return arr[0], arr[0]

    elif len(arr) == 2:
        return (arr[0], arr[1]) if arr[0] < arr[1] else (arr[1], arr[0])
    
    else:
        n = len(arr) // 2
        lmin, lmax = min_and_max2(arr[:n])
        rmin, rmax = min_and_max2(arr[n:])
        return min(lmin, rmin), max(lmax, rmax)