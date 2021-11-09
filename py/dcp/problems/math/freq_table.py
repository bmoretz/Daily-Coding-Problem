from collections import defaultdict

def get_freq_table(fn, iters : int):
    
    freq = defaultdict(int)

    for _ in range(int(iters)):
        freq[fn()] += 1

    for index in range(len(freq)):
        freq[index] /= iters

    return freq