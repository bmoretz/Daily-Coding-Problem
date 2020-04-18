'''Towers of Hanoi.

In the classic problem of the Towers of Hanoi, you have 3 towers
and N disks of different sizes which can slide onto any tower. The
puzzle starts with disks sorted in ascending order of size from
top to bottom (i.e., each disk sits on top of an even larger one).

You have the following constraints:

1.) Only one disk can be moved at a time.
2.) A disk is slid off the top of one tower onto another tower.
3.) A disk cannot be placed on top of a smaller disk.

Write a program to move the disks from the first tower to the last using stacks.
'''

def hanoi(disk, src, alt, dest):
    
    print(f'{disk} - {len(src)} - {len(alt)} - {len(dest)}')

    if src[0] == disk and ( not dest or dest[0] < disk):
        dest.append(src[0])
        src = src[1:]
    elif not alt or src[0] < alt[0]:
        hanoi(src[0], src, alt, dest)
    else:
        hanoi(src[0], src, dest, alt)

src, alt, dest = [1,2,3], [], []

print(src[0])

hanoi(3, src, alt, dest)