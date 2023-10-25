#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sumOfGroup' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts INTEGER k as parameter.
#

def sumOfGroup(k):
    # Return the sum of the elements of the k'th group.
    return k ** 3

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    k = int(input().strip())

    answer = sumOfGroup(k)

    fptr.write(str(answer) + '\n')

    fptr.close()
