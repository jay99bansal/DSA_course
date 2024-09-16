#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'substrings' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING n as parameter.
#

def substrings(n):
    MOD = int(1e9+7)
    si = ord(n[0])-ord('0')
    sni = 0
    ni = 1
    for i in range(1, len(n)):
        sni = (sni + si) % MOD
        si = ((si*10 + (ord(n[i])-ord('0'))*(ni+1))) % MOD
        ni += 1
    return (sni + si) % MOD

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = input()

    result = substrings(n)

    fptr.write(str(result) + '\n')

    fptr.close()
