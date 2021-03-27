# problem source: https://www.hackerrank.com/challenges/missing-numbers/problem
# discussion reference: https://www.hackerrank.com/challenges/missing-numbers/forum/comments/815842
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the missingNumbers function below.
def missingNumbers(arr, brr):
    missing = set()
    for n in brr:
        if n in arr:
            arr.remove(n)
        else:
            missing.add(n)
    return sorted(list(missing))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    m = int(input())

    brr = list(map(int, input().rstrip().split()))

    result = missingNumbers(arr, brr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
