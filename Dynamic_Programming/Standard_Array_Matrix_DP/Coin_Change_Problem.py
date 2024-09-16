#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getWays' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. LONG_INTEGER_ARRAY c
#

def getWays(n, c):
    m = len(c)
    dp = [[0]*(m+1) for _ in range(n+1)] #(amt, idx) -> (n+1 x m+1)
    for i in range(m+1):
        dp[0][i] = 1
    
    for i in range(1, n+1):
        for j in range(1, m+1):
            dp[i][j] = dp[i][j-1]
            if i-c[j-1] >= 0:
                dp[i][j] += dp[i-c[j-1]][j]
    
    return dp[n][m]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    c = list(map(int, input().rstrip().split()))

    # Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    ways = getWays(n, c)

    fptr.write(str(ways) + '\n')

    fptr.close()
