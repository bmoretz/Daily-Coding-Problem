'''
basic implementation of merge sort 
'''

def merge_sort1(values):

    def merge_sort(values):
        n = len(values)

        if n <= 1:
            return values

        mid = int(n/2)

        left = values[:mid]
        left = merge_sort(left)

        right = values[mid:]
        right = merge_sort(right)

        left_ptr, right_ptr = 0, 0

        result = []

        for index in range(n):

            if left_ptr == len(left):
                # left set empty, fill from right
                while right_ptr < len(right):
                    result += [right[right_ptr]]
                    right_ptr += 1

            elif right_ptr == len(right):
                # right set empty, fill from left
                while left_ptr < len(left):
                    result += [left[left_ptr]]
                    left_ptr += 1

            # take min element from both sides
            elif left[left_ptr] <= right[right_ptr]:
                result += [left[left_ptr]]
                left_ptr += 1
            else:
                result += [right[right_ptr]]
                right_ptr += 1

        return result
    
    if values == None: return None

    return merge_sort(values)