"""
Triple Step.

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.

Implement a method to count how many possible ways the child can run up the stairs.
"""

def triple_step1(n):

    def triple_step(n):
        if n < 0:
            return 0
        if n == 0:
            return 1
        else:
            return triple_step(n - 3) + triple_step(n - 2) + triple_step(n - 1)

    return triple_step(n)

def triple_step2(n):

    def triple_step(n, step_counts=[]):
        if step_counts == []:
            step_counts = [0] * (n + 1)

        if n < 0:
            return 0
        elif n == 0:
            return 1
        elif step_counts[n] != 0:
            return step_counts[n]
        else:
            total = 0

            total += triple_step(n - 3, step_counts)
            total += triple_step(n - 2, step_counts)
            total += triple_step(n - 1, step_counts)

            step_counts[n] = total

            return step_counts[n]

    return triple_step(n)