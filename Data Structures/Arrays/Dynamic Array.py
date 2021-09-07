#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'dynamicArray' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY queries
#

def dynamicArray(n, queries):
    out = []
    arr = [[] for i in range(n)]
    last_answer = 0
    
    for q in queries:
        idx = (q[1] ^ last_answer) % n
        if q[0] == 1:
            arr[idx].append(q[2])
        elif q[0] == 2:
            last_answer = arr[idx][q[2] % len(arr[idx])]
            out.append(last_answer)
            
    return out
    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    q = int(first_multiple_input[1])

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    result = dynamicArray(n, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

