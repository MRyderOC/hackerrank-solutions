#!/bin/python3

import math
import os
import random
import re
import sys


if __name__ == '__main__':
    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    # Write your code here
    total_swaps = 0
    for i in range(n):
        number_of_swaps = 0

        for j in range(n - 1):
            if a[j] > a[j + 1]:
                number_of_swaps += 1
                # Swap
                tmp = a[j]
                a[j] = a[j + 1]
                a[j + 1] = tmp

        total_swaps += number_of_swaps
        if number_of_swaps == 0:
            break

    print(f"Array is sorted in {total_swaps} swaps.")
    print(f"First Element: {a[0]}")
    print(f"Last Element: {a[-1]}")
