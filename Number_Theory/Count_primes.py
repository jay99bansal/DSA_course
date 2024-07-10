import math

class Solution:
    def countPrimes(self, n: int) -> int:
        if n<=2:
            return 0
        p = [True for i in range(n)]
        p[0] = p[1] = False
        for i in range(2, int(math.sqrt(n-1))+1):
            if p[i]:
                for j in range(i*i, n, i):
                    p[j] = False
        return p.count(True)
        