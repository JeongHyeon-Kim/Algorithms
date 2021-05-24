# problem source: https://www.hackerrank.com/challenges/two-characters/problem
# discussion reference: https://www.hackerrank.com/challenges/two-characters/forum/comments/561121
#!/bin/python3

import math
import os
import random
import re
import sys
import itertools # for combinations function

#
# Complete the 'alternate' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternate(s):
    # Write your code here
    x = set(s)
    m = 0
    l = list(map(set, itertools.combinations(x, 2))) # Consider a combination 'a' and 'b'
    for i in l:
        y = x - i # the set y don't have 'a' and 'b'.
        z = s #  a copy of our input parameter
        for j in y:
            z = z.replace(j, "") # z will be modified such that the string containing only 'a' and 'b.
        r = ("".join(i)) * (len(z)//2) #  r is our desired string (abab .... (a / b) or baba ..... (a / b))
        if r + r[0] == z or r == z or r == z[::-1] or r[1] + r ==z : # : The four combinations of r mentioned in above should be compared with z
            m = max(m, len(z)) # If anyone of four conditions satisfied, then we'll update the maximum length into m.
    return m

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    l = int(input().strip())

    s = input()

    result = alternate(s)

    fptr.write(str(result) + '\n')

    fptr.close()
